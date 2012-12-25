# include <stdio.h>
# include <stdlib.h>
struct btreenode
{
	struct btreenode *right,*left ;
	int data ;
} ;

void insert ( struct btreenode **, int ) ;
int delete (struct btreenode**,int);
void search ( struct btreenode **, int, struct btreenode **,struct btreenode **, int * ) ;
void print( struct btreenode** );
void main()
{
    int flag = 1;
    int choice,val = 0;
    int Value;
    struct btreenode *bt = NULL;
 
    printf("\n\n<==== Program for Binary Search Tree Insert,Delete and Display Tree ==>");
 
    while( flag )
    {
        printf("\n1 : Insert element in tree");
        printf("\n2 : Display elements in tree");
        printf("\n3 : Delete element from tree");
        printf("\n4 : Exit");
        printf("\n\nPlease enter a choice : ");
 
        scanf("%d", &choice);
 
        switch( choice )
        {
        case 1 :printf("Enter the value to insert : ");
                scanf("%d", &Value);
                insert( &bt,Value );
                break;
 
        case 2 :printf("\nInorder :");  
                print( &bt );
                break;
 
        case 3 :printf("Enter the element to delete : ");
                scanf("%d", &Value);
                val = delete( &bt,Value );
                if(val == 1)
                    printf("\nDeleted!!\n");
                else
                    printf("\nNot Found!!\n");
                break;
 
        case 4 :flag = 0;
                break;
 
        default : printf( "Please insert a valid choice" );
        }
    }
 
  }
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

void print( struct btreenode **sr )
{
         
   struct btreenode* current = NULL;
    
    if( *sr != NULL )
    {  
        current = *sr;
        print( &current->left );
        printf("%d\t", current->data);
        print( &current->right );
    }
}

int delete ( struct btreenode **sr, int num )
{
	int found ;
	struct btreenode *parent, *x, *succ ;

	/* if tree is empty */
	if ( *sr == NULL )
	{
		printf ( "\nTree is empty" ) ;
		return ;
	}

	parent = x = NULL ;

	/* call to search function to find the node to be deleted */
	search ( sr, num, &parent, &x, &found );

	/* if the node to deleted is not found */
	if ( found == 0 )
	{
		printf ( "\nData to be deleted, not found" ) ;
		return ;
	}

	/* if the node to be deleted has no child */
	if ( x -> left == NULL && x -> right == NULL )
	{
		if ( parent -> right == x )
			parent -> right = NULL ;
		else
			parent -> left = NULL ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only right */
	if ( x -> left == NULL && x -> right != NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> right ;
		else
			parent -> right = x -> right ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only left child */
	if ( x -> left != NULL && x -> right == NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> left ;
		else
			parent -> right = x -> left ;

		free ( x ) ;
		return ;
	}
	/* if the node to be deleted has two children */
	if ( x -> left != NULL && x -> right != NULL ) 
	{
		parent = x ;
		succ = x -> right ;

		while ( succ -> left != NULL )
		{
			parent = succ ;
			succ = succ -> left ;
		}

		x -> data = succ -> data ;
		x = succ ;
	}
}

void search ( struct btreenode **sr, int num, struct btreenode **par, struct
		btreenode **x, int *found )
{
	struct btreenode *query ;

	query = *sr ;
	*found = 0 ;
	*par = NULL ;

	while ( q != NULL )
	{
		/* if the node to be deleted is found */
		if ( query -> data == num )
		{
			*found = 1;
			*x = query ;
			return ;
		}

		*par = query ;

		if ( query -> data > num )
			query = query -> left ;
		else
			query = query -> right ;
	}
}

