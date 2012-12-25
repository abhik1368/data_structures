# include <stdio.h>
# include <stdlib.h>
struct btreenode
{
	struct btreenode *right,*left ;
	int data ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;
void preorder ( struct btreenode * ) ;
void postorder ( struct btreenode * ) ;

void main( )
{
	struct btreenode *bt ;
	int req,max,i = 1,num;
        bt = NULL ;  /* empty tree */

        printf ( "Specify the number of items to be inserted: " ) ;
	scanf ( "%d", &req ) ;

	while ( i++ <= req )
	{
		printf ( "Enter the data: " ) ;
		scanf ( "%d", &num ) ;
		insert ( &bt, num ) ;
	}
        printf ( "\nIn-order   Traversal: " ) ;
	inorder ( bt ) ;

	printf ( "\nPre-order  Traversal: " ) ;
	preorder ( bt ) ;

	printf ( "\nPost-order Traversal: " ) ;
	postorder ( bt ) ;
    max = maxdepth(bt);
    printf("\nMaximum depth %d:",max);
    printf("\n");   
                      
}

/* inserts a new node in a binary search tree */
void insert ( struct btreenode **sr, int num )
{
        
	return ;
}

/* traverse a binary search tree in a Left->Data->Right*/
void inorder ( struct btreenode *sr )
{
	
		return ;
}

/* traverse a binary search tree in a Data->Left->right*/
void preorder ( struct btreenode *sr )
{
	
		return ;
}


/* traverse a binary search tree in Left->Right->Data*/
void postorder ( struct btreenode *sr )
{
	
		return ;
}

int  maxdepth(struct btreenode *sr)
{  

           
} 
          
}
