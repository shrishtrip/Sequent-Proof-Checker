#include<bits/stdc++.h> 
using namespace std; 


int len(string s){	/**   * Return the index of first  occurence of  "/"  */
	int count=0;
	while(s[count]!='/')	/**   *  loop to increment the count*/
	count++;
	return count;		/**   *  return the count*/
}



int proof_line_no(int n,char c[][100]){		/**   * Return the line no of proof start */
    if(n==0 && n==1)						/**   *  Initial cases*/
    	return 0;
    else if(n==2)							/**   *  Initial cases*/	
    	return 1;
    	
	for (int i = 1; i < n+1; i++){		/**   *  loop to check P's occurence */
      for (int j = 1; j < 100; j++) 
      		if(c[i][j]=='\0' && c[i][j-1]!='P' && c[i][j+1]!='\0')
       			return i-1;				/**   *  Return the line no*/
       		else if(c[i][j]=='\0' && c[i][j-1]=='P')
       		    break;
			else
				continue;
	}

}


int and_i(int l,int n,char c[][100]){			/**   * Check and intorduction*/

	for (int i = l; i < n+1; i++){				/**   * Loop to traverse the 2D array*/
    	for (int j = 0; j < 100; j++) {
	    	
			if(c[i][j]=='/' && c[i][j+1]=='^' &&  c[i][j+2]=='i'){	/**   *Check the occurence of /^i */
 	 		    int l1,l2;											/**   * Index for the line nos. */
				l1=j+4;
				int temp1=l1;										/**   * Starting index of 1st no. */	
				while(c[i][l1]!='/')								/**   * Loop to get the ending index of 1st no. */
				l1++;
				l2=l1+1;
				int temp2=l2;										/**   * Starting index of 2nd no. */	
				while(c[i][l2]!='\0')								/**   * Loop to get the ending index of 2nd no. */							
				l2++;												
				int p=0,q=0;
				for(int k=temp1;k<(l1);k++)
				p=p*10+(int(c[i][k])-48);							/**   * 1st Line no  */
				for(int k=temp2;k<(l2);k++)
				q=q*10+(int(c[i][k])-48);							/**   * 2nd Line no  */
				int ll1=len((string)c[p]);int ll2=len((string)c[q]);	/**   * Index of first /  */
				string appended_string="("+((string)c[p]).substr(0,ll1)+"^"+((string)c[q]).substr(0,ll2)+")";		/**   * Concatinate the 2 strings with ( ^ )  */
				int ll3=len((string)c[i]);
				string check=((string)c[i]).substr(0,ll3);				/**   * Substring of the proof */
				if(appended_string==check){								/**   * compare the appended and given string  */
				break;	
				}
				else
				return 0;
			}
			
			else if(c[i][j]=='/' && c[i][j+1]=='^'  &&  c[i][j+2]!='i'){		/**   * Goto next line if /^i not occurred*/
				break;	
			}
			
			
			else if(c[i][j]=='/' && c[i][j+1]!='^'){			/**   * Goto next line if /^i not occurred*/
				break;	
			}
			
			else{
			    continue;	
		    }
		}
				
		
	}
	
	return 1;   		/**   *  Return 1 if every ^i is correct*/
} 


int and_e(int l,int n,char c[][100]){		/**   *Check And elimination*/

	for (int i = l; i < n+1; i++){		/**   * Loop to traverse the 2D array*/
    	for (int j = 0; j < 100; j++) {
	    	
			if(c[i][j]=='/' && c[i][j+1]=='^'  &&  c[i][j+2]=='e'){ 		/**   *Check the occurence of /^e */
 	 		    int l1,l2;													/**   * Index for the line nos. */
				l1=j+3,l2=j+5;
				int temp1=l1;												/**   * Starting index of 1st no. */	
				while(c[i][l1]!='/')										/**   * Loop to get the ending index of 1st no. */
				l1++;
				l2=l1+1;
				int temp2=l2;												/**   * Starting index of 2nd no. */	
				while(c[i][l2]!='\0')											/**   * Loop to get the ending index of 2nd no. */
				l2++;	
				int p=0,q=0;
				for(int k=temp1;k<(l1);k++)
				p=p*10+(int(c[i][k])-48);									/**   * 1st Line no  */
				for(int k=temp2;k<(l2);k++)
				q=q*10+(int(c[i][k])-48);										/**   * 2nd Line no  */
				int ll1=len((string)c[q]),ll2=len((string)c[i]);			/**   * Index of first /  */
				string str=((string)c[q]).substr(1,ll1-2);				/**   * Substring of the proof */
				int x=0;
				string str1;
				int flag=1;
				while(flag){												/**   * Loop to get index where no_of_( == no_of_)*/
					int left=0,right=0;
					for(int i=0;;i++){
						
							if(str[i]=='('){							/**   * Count no of ( */
								left++;
							}
							
							else if(str[i]==')'){							/**   *  Count no of ) */
								right++;
							}
							
							if(left==0){									/**   *  Check if there is no ()*/
								x=1;
								flag=0;
								break;
							}
									
							if(left==right){							/**   * Check if no_of_( == no_of_) */
								x=i;		
								flag=0;
								break;	
								}
						}
						
					
						
					}
					
					
						if(p==1){									/**   *  if ^e1 take first part of the string*/
							if(x==1){	
								str1=str[0];
							}
							else{
					    str1=((string)str).substr(1,x);
					    	}
						}
						
						else if(p==2){								/**   * if  ^e2 take second part of the sring */
							if(x==1){
								str1=str[2];
							}
							else{
								int y=str.length();
							str1=((string)str).substr(x+2,y-(x+2));	
							}
						}
				
			string str2=((string)c[i]).substr(0,ll2);			/**   *  Substring of the given proof line */
			if(str1==str2)											/**   *  Check if both strings are equal */
					break;
				else
				    return 0;
				
			}
			
			else if(c[i][j]=='/' && c[i][j+1]=='^'  &&  c[i][j+2]!='e'){				  /**   *  Goto next line if /^e not occurred*/
				break;	
			}
			
			else if(c[i][j]=='/' && c[i][j+1]!='^'){  								/**   *  Goto next line if /^ not occurred */
				break;	
			}
			
			else{
			    continue;	
		    }
		}
				
	}
	
	return 1;										/**   *  If every ^e is correct return 1*/
} 


int or_i(int l,int n,char c[][100]){  				 /** * Check or introduction*/
	for (int i = l; i < n+1; i++){														/**   * Loop to traverse the 2D array*/
    	for (int j = 0; j < 100; j++) {
			if(c[i][j]=='/' && c[i][j+1]=='V'  &&  c[i][j+2]=='i'){						/**   *Check the occurence of /Vi */
		 	 	    int l1,l2;	/**   * Index for the line nos. */
					l1=j+4;
					int temp1=l1;/**   * Starting index of 1st no. */	
					while(c[i][l1]!='/')	/**   * Loop to get the ending index of 1st no. */
					l1++;
					l2=l1+1;
					int temp2=l2;/**   * Starting index of 2nd no. */	
					while(c[i][l2]!='\0')	/**   * Loop to get the ending index of 2nd no. */
					l2++;
					int p=0,q=0;
					for(int k=temp1;k<(l1);k++)
					p=p*10+(int(c[i][k])-48);/**   * 1st Line no  */
					for(int k=temp2;k<(l2);k++)
					q=q*10+(int(c[i][k])-48);/**   * 2nd Line no  */
					string check=((string)c[i]).substr(0,len((string)c[i]));
					int y=check.length();
					string str=check.substr(1,y-2);
					int x=0;
					string str1;
					int flag=1;
					while(flag){
					int left=0,right=0;
					for(int i=0;;i++){  			/**   *Loop to get the no_of_( and no_of_) */
						
							if(str[i]=='('){
								left++;						/**   * Increment the left count*/
							}
							
							else if(str[i]==')'){
								right++;					/**   *Inceremet the right count */
							}
							
							if(left==0){
								x=1;
								flag=0;
								break;
							}
								
							if(left==right){
								x=i;
								flag=0;
								break;	
								}
						}
					}
					
					if(p==1){										/**   *  if ^i1 take first part of the string*/
							if(x==1){
								str1=str[0];
							}
							else{
							str1=((string)str).substr(1,x);
					    	}
						}
						
						else if(p==2){								/**   *  if Vi2 take first part of the string*/
							if(x==1){
								str1=str[2];
							}
							else{
								int y=str.length();
								str1=((string)str).substr(x+2,y-(x+2));	
							}
						}
			int ll2=len((string)c[q]);
			string str2=((string)c[q]).substr(0,ll2);		/**   *  Get the substring of the given proof line*/
			if(str1==str2){									/**   * If same the continue else return 0 */
					break;
				}
					
				else{
					return 0;
				}
			}
			else if(c[i][j]=='/' && c[i][j+1]!='V'){			/**   *  Goto next line no occurence of Vi*/
				break;	
			}
			else{
			    continue;	
		    }
		}
	}
	
	return 1;					/**   * Return 1 if every occurrence of V is correct */
}


int imp_e(int l,int n,char c[][100]){		/**   *  Check implication elimination*/
for (int i = l; i < n+1; i++){				/**   * Loop to traverse the 2D array*/
    	for (int j = 0; j < 100; j++) {
	    	
			if(c[i][j]=='/' && c[i][j+1]=='>'  &&  c[i][j+2]=='e'){		/**   *Check the occurence of />e */
				int l1,l2;	/**   * Index for the line nos. */
				l1=j+4;
				int temp1=l1;/**   * Starting index of 1st no. */	
				while(c[i][l1]!='/')/**   * Loop to get the ending index of 1st no. */
				l1++;
				l2=l1+1;
				int temp2=l2;/**   * Starting index of 2nd no. */	
				while(c[i][l2]!='\0')/**   * Loop to get the ending index of 2nd no. */
				l2++;
				int p=0,q=0;
				for(int k=temp1;k<(l1);k++)
				p=p*10+(int(c[i][k])-48);/**   * 1st Line no  */
				for(int k=temp2;k<(l2);k++)
				q=q*10+(int(c[i][k])-48);/**   * 2nd Line no  */
				int ll1=len((string)c[p]),ll2=len((string)c[q]),ll3=len((string)c[i]);
				string str1=((string)c[q]).substr(0,ll2);
				string str=((string)c[p]).substr(0,ll1);
				str=str.substr(1,(str.length())-2);
				int x=0;
				int flag=1;
				while(flag){
					int left=0,right=0;
					for(int i=0;;i++){	/**   *Loop to get the no_of_( and no_of_) */
						
							if(str[i]=='('){
								left++;	/**   * Increment the left count*/
							}
							
							else if(str[i]==')'){
								right++;		/**   *Inceremet the right count */
							}
							
							if(left==0){
								x=1;
								flag=0;
								break;
							}
								
							if(left==right){
								x=i;
								flag=0;
								break;	
								}
						}
					}
		
					string str2,str3;
					if(x==1){           /**   *  if ^i1 substring appended in start*/
					str2=((string)str).substr(0,x);
					str3=((string)str).substr(x+1,1);	
					}
					
					else		/**   *  if ^i2 substring appended at last*/
					{
					int y=str.length();
					str2=((string)str).substr(0,x+1);
					str3=((string)str).substr(x+2,y-(x+2));	
					}
					
				    string str4=((string)c[i]).substr(0,ll3);
					if(str1==str2 && str3==str4)		/**   *  Check if given proof substring equal to generated string*/
						break;
					else
						return 0;
				
				
			}
			
			else if(c[i][j]=='/' && c[i][j+1]!='>'){		/**   * Goto next line if Vi doesn't coccurs */
				break;	
			}
			
			else{
			    continue;	
		    }
		}
				
	}
	
	return 1;		/**   * Return 1 if every occurence of V is correct */
}




int main(){

	int n; 										/**   *No of lines in proof  */
	cin>>n;										/**   *  Collect no of proof lines from the user*/

	cin.ignore();								/**   * Ignore the first press of enter */


	char s[n+1][100];							/**   *  Declare a 2D character array*/
	

	for(int i=0;i<n+1;i++){						/**   *  Loop to initialise the 2d array */
	for(int j=0;j<100;j++) s[i][j]='\0';
	}

    

    for(int i=1;i<n+1;i++)						/**   * Collect the proof lines from the user */
    {
    cin.getline(s[i],100); 
	}
  
 int a=0;										/**   *  Flag variable to check the correctness*/
a=proof_line_no(n,s);							/**   *  Call the proof_line function*/
if(a==0)
	cout<<"Enter Some Statements"<<endl;
else
	cout<<"Proof Starts From = "<<proof_line_no(n,s)+1<<endl;
 

 

a=and_i(proof_line_no(n,s)+1 , n ,s);			/**   *  Call the and_i function */
if(a == 1)
	cout<<"And Introduction  : Correct"<<endl;
else
	cout<<"And Introduction  : Not Correct"<<endl;




	
a=and_e(proof_line_no(n,s)+1 , n ,s);			/**   *  Call the and_e function*/
if(a == 1)
	cout<<"And Elimination   : Correct"<<endl;
else
	cout<<"And elimination   : Not correct"<<endl;


	
a=or_i(proof_line_no(n,s)+1 , n ,s);			/**   *  Call the or_i function*/
if(a == 1)
	cout<<"Or Introduction   : Correct"<<endl;
else
	cout<<"Or Introduction   : Not Correct"<<endl;


a=imp_e(proof_line_no(n,s)+1 , n ,s);			/**   *  Call the imp_e function*/
if(a == 1)
	cout<<"Implication Elimination :  Correct"<<endl;
else
	cout<<"Implication Elimination :  Not correct"<<endl;




	return 0;
	
}
