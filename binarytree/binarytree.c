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
        if ( *sr == NULL )
	{
		*sr = malloc ( sizeof ( struct btreenode ) ) ;

		 (*sr) -> left = NULL ;
		 (*sr) -> data = num ;
		 (*sr) -> right= NULL ;
		return ;
	}
          /*search the node to which the new node will be attached*/ 	
        else  
	{
		/* if new data is less, traverse to left */
		if ( num < (*sr)-> data )
			insert ( &((*sr)-> left), num ) ;
		else
			/* else traverse to right */
			insert ( &((*sr)-> right), num ) ;
	}
	return ;
}

/* traverse a binary search tree in a Left->Data->Right*/
void inorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> left) ;

		/* print the data of the node whose leftchild is NULL or the path
		   has already been traversed */
		printf ( "\t%d", sr -> data ) ;

		inorder ( sr -> right) ;
	}
	else
		return ;
}

/* traverse a binary search tree in a Data->Left->right*/
void preorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		/* print the data of a node */
		printf ( "\t%d", sr -> data ) ;
		/* traverse till leftchild is not NULL */
		preorder ( sr -> left) ;
		/* traverse till rightchild is not NULL */
		preorder ( sr -> right) ;
	}
	else
		return ;
}


/* traverse a binary search tree in Left->Right->Data*/
void postorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		postorder ( sr -> left) ;
		postorder ( sr -> right) ;
		printf ( "\t%d", sr -> data ) ;
	}
	else
		return ;
}

int  maxdepth(struct btreenode *sr)
{  int ldepth,rdepth=0; 
        if(sr==NULL){
            return 0;
        }

        else{
        // compute the depth of subtree
        ldepth = maxdepth( sr -> left);
        rdepth = maxdepth( sr -> right);
        
        if (ldepth > rdepth) 
            return (ldepth+1);
           
        else
            return (rdepth+1);

           
} 
          
}