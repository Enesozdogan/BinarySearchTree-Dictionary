#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 30


struct n{
	char word[128];
	struct n *left, *right;
	int dosya[20];
	int dongu;
	
	
};


typedef struct n bst;
	bst* insert(bst *root,char x[],int hangi_dosya);
	void Search(bst *root,char x[],int *flag_se);
	bst* dosyadan_oku(bst *root,FILE *f, char x[], int hangi_dosya);
	void inorder( bst *root,char filename[]);
	void dosyalari_yaz(bst* root);
	int check_sil(bst *root,int hangi_dosya);
	void dosya_sil(bst *root,char filename[]);
	
int main(){
	
	
	bst* root=NULL;
	int i=0,flag=0,hangi_dosya=65;
	FILE *fx;
	char x[max];
	
	char filename[100];
	int q;
	printf("Yeni dosya eklemek:0\nDosya Silmek:1\nKelime aramak:2\nCikmak:3\n");
	printf("islem sec:");
	scanf("%d",&q);
	while(q!=3){
	
		if(q==0){
			printf("Eklenecek dosya:");
			scanf("%s",filename);
			fx=fopen(filename,"r");
			if(check(filename,"b.txt")==0){
				root=dosyadan_oku(root,fx,x,hangi_dosya+1);
				
			}
			else if(check(filename,"c.txt")==0){
				root=dosyadan_oku(root,fx,x,hangi_dosya+2);
			}
			else if(check(filename,"d.txt")==0){
				root=dosyadan_oku(root,fx,x,hangi_dosya+3);
			}
			else if(check(filename,"a.txt")==0){
				root=dosyadan_oku(root,fx,x,hangi_dosya);
			}	
		}
		else if(q==1){
			printf("Silinecek dosya:");
			scanf("%s",filename);
			//dosya_sil(root,filename);
			inorder(root,filename);			
		}
		else if(q==2){
				dosyalari_yaz(root);
		}
		printf("islem sec:");
		scanf("%d",&q);
		
		
	
	}
	
	
	
}

bst* dosyadan_oku(bst *root,FILE *f, char x[], int hangi_dosya){
	int i=0,j=0;
	int flag_se;
	switch(hangi_dosya){
		case 65:
			for(j=0;j<7;j++){
				read_words(f,x);
				
				flag_se=0;
				Search(root,x,&flag_se);
				
				if(flag_se!=1){
					root=insert(root,x,hangi_dosya);
					//printf("%s",root->word);
					
				}
				
				
			}
			break;
	
		case 66:
			for(j=0;j<9;j++){
				read_words(f,x);
				flag_se=0;
				Search(root,x,&flag_se);
				if(flag_se!=1){
					root=insert(root,x,hangi_dosya);
					//printf("%s",root->word);	
				}
				
				
			}
			break;
		case 67:
			for(j=0;j<7;j++){
				read_words(f,x);
				flag_se=0;
				Search(root,x,&flag_se);
				if(flag_se!=1){
					root=insert(root,x,hangi_dosya);
					//printf("%s",root->word);	
				}
				
				
			}
			break;
		case 68:
			for(j=0;j<6;j++){
				read_words(f,x);
				flag_se=0;
				Search(root,x,&flag_se);
				if(flag_se!=1){
					root=insert(root,x,hangi_dosya);
					//printf("%s",root->word);	
				}
				
				
			}
			break;
	}
	
}

void inorder( bst *root,char filename[]) {
	int hangi_dosya;
	bst* temp;
	if(check(filename,"a.txt")==0){
		hangi_dosya=65;
	}
	else if(check(filename,"b.txt")==0){
		hangi_dosya=66;
	}
	else if(check(filename,"c.txt")==0){
		hangi_dosya=67;
	}
	else if(check(filename,"d.txt")==0){
		hangi_dosya=68;
	}
     if(root==NULL)
        return;
        
    	inorder(root->left,filename);
    	if(check_sil(root,hangi_dosya)==1){
    	free(root);
    	}
    	inorder(root->right,filename);
    
  
}

void read_words (FILE *f, char x[]) {
	if(f==NULL){
		printf("dosya bulunamadi\n");
	}
   	fscanf(f, " %1023s", x);
   
  
}

bst* insert(bst *root,char x[],int hangi_dosya){
	
  
  int j=0;
  if(root==NULL){
  	root=(bst *)malloc(sizeof(bst));
  	strcpy(root->word,x);
  	root->dongu=0;
  	
  	root->dosya[root->dongu]=hangi_dosya;
  	
  	//printf("kelime:%s:%c\n",root->word,root->dosya[root->dongu]);
	root->dongu+=1;
  	
  	
  	root->left=NULL;
  	root->right=NULL;
  	return root;
  }
    
  else{
     
       if(check(x,root->word)>0){
       
         root->right=insert(root->right,x,hangi_dosya);
         return root;
       }

       else if(check(x,root->word)<0)
     {
     	
        root->left=insert(root->left,x,hangi_dosya);
        return root;
     }
       else if(check(root->word,x)==0){
         
         //printf("\nbu kelimeden var:%s\n",root->word);
           root->dosya[root->dongu]=hangi_dosya;
          	root->dongu+=1;
        	
        	return root;
        	
         
       }

   }
     

}

void Search(bst *root,char x[],int *flag_se){
 		int j;
 		if(root!=NULL){
 			if(check(x,root->word)==0){
 				*flag_se=1;
			 }
 			else if(check(x,root->word)>0){
 				
 				return Search(root->right,x,&flag_se);
 				
			 }
			 else {
			 	
			 	return Search (root->left,x,&flag_se);
			 }
		 }
 }
 


int check(char a[],char b[]){
     int i=0,j=0,c=0;
     //printf("a:%d===b:%d",strlen(a),strlen(b));
    if(strlen(a)==strlen(b)){ 
     while(((a[i]!='\0') && (b[i]!='\0')) && (c==0)){
     	if(a[i]>b[i]){
     		c=1;
     		
     	
		 }	
     	else if(b[i]>a[i]){
     		c=-1;
     		
		 }	
     	else{
     		
     		c=0;
		 }
		 i++;
		 
		 
	 }
	}
	 else{
	 	while(((a[i]!='\0') && (b[i]!='\0')) && (c==0)){
     	if(a[i]>b[i]){
     		c=1;
     		
     	
		 }	
     	else if(b[i]>a[i]){
     		c=-1;
     		
		 }
		 i++;
	}
	 	if(c==0){
	 		if(strlen(a)>strlen(b)){
	 			c=1;
			 }
			 else{
			 	c=-1;
			 }
		 }
	 }
	 return c;
	} 
	 

void dosyalari_yaz(bst* root){
  int flag=0;
  int i=0;
  bst *ptr;
  ptr=root;
  char w[10];
  printf("\nEnter word:");
  scanf("%s",w);
  while(ptr!=NULL && flag==0){
    if(check(w,ptr->word)>0)
       ptr=ptr->right;
    else if(check(w,ptr->word)<0)
          ptr=ptr->left;
    else if(check(w,ptr->word)==0){
       flag=1;
       for(i=0;i<ptr->dongu;i++){
       	printf("%c",ptr->dosya[i]);
	   }
	   printf("\n");
	   
    }

    }
    if(flag==0)
      printf("\nWord not found\n");
}

int check_sil(bst *root,int hangi_dosya){
	int i=0,c=0;
	printf("%d\n",root->dongu);
	while(i<(root->dongu) && (c==0)){
		if((root->dosya[i])==hangi_dosya){
			
			printf("i:%d dosya[i]:%c--%c\n",i,root->dosya[i],hangi_dosya);
			c=1;
		}
		i++;
	}
	return c;	
}

void dosya_sil(bst *root,char filename[]){
	int hangi_dosya;
	bst* temp;
	if(check(filename,"a.txt")==0){
		hangi_dosya=65;
	}
	else if(check(filename,"b.txt")==0){
		hangi_dosya=66;
	}
	else if(check(filename,"c.txt")==0){
		hangi_dosya=67;
	}
	else if(check(filename,"d.txt")==0){
		hangi_dosya=68;
	}
	if(root==NULL){
		return;
	}
	if(check_sil(root,hangi_dosya)==1){
		dosya_sil(root->right,filename);
		dosya_sil(root->left,filename);
		free(root);
	}
	
}


