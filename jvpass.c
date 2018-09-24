#include <stdio.h>
#include <stdlib.h>

int currentDeep;

typedef struct node {
    struct node * left;
    struct node * right;
    int value;
}Node;

int depth(Node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       int lDepth = depth(node->left); 
       int rDepth = depth(node->right); 

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
int isAVL(Node * node){
    if(node == NULL)return 0;
    int nivelDeBalanceamento = (depth(node->left))-(depth(node->right));
    if(-1>nivelDeBalanceamento || 1<nivelDeBalanceamento) return 0;
    isAVL(node->left);
    isAVL(node->right);
    return 1;
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
        printf("l: %d",depth(mainRoot->left));
        printf("r: %d",depth(mainRoot->right));
        isAVL(mainRoot)?printf("T\n"):printf("F\n");
        
        
    }

    
}

