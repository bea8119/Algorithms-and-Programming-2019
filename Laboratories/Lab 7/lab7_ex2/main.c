#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int mult(int x, int y);
int bin(int *b, int x, int *n);
int catalan (int n);
int countSpaces (char *s);
int isPalindrome (char *s, int l);
//          #F
void triangle (int n, int i );
void triangle2 (int n, int i, int j  );
int main()
{
  /*  int res;
 res=mult(4,5);
 printf(" %d", res);

 int b[20];
 int x, n=0;
 printf("insert n for binary:\n");

 scanf("%d", &x);
 bin(b, x, &n);
 printf("Result: \n");
 for(int i=n-1; i>=0; i--){
    printf("%d", b[i]);
 }

 int n, res;
 for(n=0; n<10; n++){
    res=catalan(n);
    printf("\n%d:   %d",n, res);
 }

 char str[] = "This is a string   with spaces!";
int  res=countSpaces(str);
 printf("\n there are  %d white spaces ", res);

char str[] = "  cmom ";
int  res=isPalindrome(str, strlen(str)-1);
if(res==0){
     printf("Yes it is palindrome" );
}else{
    printf("No" );
}
*/
triangle2(4,1, 0);


    return 0;
}

//          #A
int mult(int x, int y ){
    if(y==0)
        return 0;
    return x+mult(x, y-1);
}

//          #B
int bin(int *b, int x, int *n){

if( x==0){
    return 1;
}

b[*n]=x%2;
*n=*n+1;
return bin( b, (x/2), n);

}


//            #C
int catalan (int n){

if(n<=1)
    return 1;
int i;
int res=0;
for(i=0; i<n; i++){
    res=res+catalan(i)*catalan(n-1-i);

}
return res;
}

//      #D
int countSpaces (char *s){
static int  i=0, count=0;

if(s[i]=='\0'){
    return count;
}
if(s[i]==' '){
    count++;
}
i++;
countSpaces(s);

}


//          #E
int isPalindrome (char *s, int l){
int i=strlen(s)-(l+1);
if(s[i]==s[l]){
    if(i+1==l || i==l){
        return 0;
        printf("just  c " ); }
    isPalindrome(s, l-1); }
else
return 1;
}


//          #F
void triangle (int n, int i ){
int j;

if(n<i)  return;

for(j=0; j<i; j++) printf("%d", i);

printf("\n");
triangle(n, i+1);
}

//          #G
void triangle2 (int n, int i, int j ){
    printf("%d", i);
if(n==i && j==i-1)  return;



if(j<i-1){
    triangle2(n, i, j+1);
} else {
    printf("\n");
triangle2(n, i+1, 0);
}


}








