/*
	Finding s%n where s is a big string containing digits from 0 to 9
*/

char c[] = {};



long long unsigned int getvalue(char s[], int d) {
	unsigned long long int ret=0;
	int i;
	for(i=d-1; i>=0; i--)
		ret=ret*10+s[i]-'0';
	
	return ret;
}

long long unsigned int get(char s[], int d) {
	unsigned long long int ret=0;
	int i;
	for(i=0; i<d; i++)
		ret=ret*10+s[i]-'0';
	
	return ret;
}

int populate(char array[], int n) {
	int i=0;
	while(n!=0) {	
		array[i] = (n%10 + '0');
		n = n/10;
		i++;
	}
	return i;
}

int merger(char array[],int d,int array_length,int index) {
	//printf("ss\n");
	int i = 0, j;
	for(j=array_length-1; j>=0; j--) {
		c[i] = array[j];
		i++;		
	}
	for(j=d; j<index; j++) {
		c[i] = c[j];
		i++;
	}
	return i;
}

unsigned long long modulo(int m, int index) {
	int d = 16,i;
	//for(i=0; i<index; i++) printf("%d ",c[i]);
	if(index > d) {	
		char temp[d];
		int i;
		for(i=0; i<d; i++) {
			temp[i] = c[i];
		}
		//for(i=0; i<d; i++) printf("%d ",temp[i]);
		
		unsigned long long int tempnum = get(temp,d);
		//printf("%llu\n",tempnum);
		tempnum = tempnum % m;
		//printf("%llu\n",tempnum);
		char array[m];
		int array_length = populate(array,tempnum);
		//for(i=0; i<array_length; i++) printf("%d",array[i]);
		//printf("%d %d ",array_length,index);
		index = merger(array,d,array_length,index);
		//for(i=0; i<index; i++) printf("%d",temp[i]);
		//printf("\n");
		
		return modulo(m,index);

	} else {
		unsigned long long int tempnum = getvalue(c,index);
		tempnum = tempnum % m;
		return tempnum;
	}	
}


