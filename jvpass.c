#include <stdio.h>
#include <stdlib.h>

int currentDeep;

typedef struct node {
    struct node * left;
    struct node * right;
    int value;
}Node;

int maxDepth(Node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  
Node * insereEmArvore(Node * arvore, int info){  
    if(arvore == NULL){
        Node * new = malloc(sizeof(Node));
        new->value = info;
        arvore = new;
            
    }else{
        if(info < arvore->value){
            arvore ->left = insereEmArvore(arvore->left,info);       
        }else{
            arvore->right = insereEmArvore(arvore->right,info);    
        }
    }   
    return arvore;
}
 
int main(void){
    int testCaseNumber,valuesNumber;
    scanf("%i",&testCaseNumber);    
    while(testCaseNumber--){
        scanf("%d",&valuesNumber);
        Node * mainRoot = NULL;
        
        while(valuesNumber--){
            int nodeValue,nodeDeep;
            scanf("%d",&nodeValue);
            if(nodeValue == -1)continue;
            
            mainRoot = insereEmArvore(mainRoot,nodeValue);
            
        }
        printf("%d",maxDepth(mainRoot));
        
        
    }

    
}

