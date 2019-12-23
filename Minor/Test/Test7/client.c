#include<stdio.h> 
#include<sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
#include <netdb.h>

#define MAX_TREE_HT 100 

 char buffer[100];
struct decompress
{
char msgg[100];
char key;
char value[100];



};
char decompress_string[100]={0};

struct decompress str[26];


// function that decompress___ compress__msg
int use_decom =0;
int use_decomsg_size =0;

int use_per= 0;
float percDec;

void decompress_msg( char *com_msg)
{
int i,j;
char original_msg[100] = {0};
char a;
int size=0;
for(i =0;com_msg[i]!='\0';i++)
{
size++;
}
int original_size = 8*use_decomsg_size;
//printf("\n%d\n",original_size);
//printf("\n%d\n",size);
percDec = (original_size-size)*100/original_size;
printf("\nPERCENT%f\n",percDec);
for(i =0;i<use_decomsg_size;i++)
{


for(j=0;j<use_decom;j++)
{
if(strcmp(str[i].msgg, str[j].value)==0)
{
a = str[j].key;
strncat(original_msg, &a, 1); 
}
}

}
printf("\nOriginal Message: %s\n",original_msg);
}
char str1[100]={0};

int findSize(char str[])
{

int i ,size;
for(i =0;str[i]!='\0';i++)
{
size++;
}
return size;
}
  
int k =0;


// A Huffman tree node 

struct MinHeapNode { 
  
    // One of the input characters 
    char data; 
  
    // Frequency of the character 
    unsigned freq; 
  
    // Left and right child of this node 
    struct MinHeapNode *left, *right; 
}; 
  
// A Min Heap:  Collection of 
// min-heap (or Huffman tree) nodes 
struct MinHeap { 
  
    // Current size of min heap 
    unsigned size; 
  
    // capacity of min heap 
    unsigned capacity; 
  
    // Array of minheap node pointers 
    struct MinHeapNode** array; 
}; 
  
// A utility function allocate a new 
// min heap node with given character 
// and frequency of the character 
struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
    struct MinHeapNode* temp 
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode)); 
  
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
  
    return temp; 
} 
  
// A utility function to create 
// a min heap of given capacity 
struct MinHeap* createMinHeap(unsigned capacity) 
  
{ 
  
    struct MinHeap* minHeap 
        = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
  
    // current size is 0 
    minHeap->size = 0; 
  
    minHeap->capacity = capacity; 
  
    minHeap->array 
        = (struct MinHeapNode**)malloc(minHeap-> 
capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 
  
// A utility function to 
// swap two min heap nodes 
void swapMinHeapNode(struct MinHeapNode** a, 
                     struct MinHeapNode** b) 
  
{ 
  
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// The standard minHeapify function. 
void minHeapify(struct MinHeap* minHeap, int idx) 
  
{ 
  
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = right; 
  
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], 
                        &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
} 
  
// A utility function to check 
// if size of heap is 1 or not 
int isSizeOne(struct MinHeap* minHeap) 
{ 
  
    return (minHeap->size == 1); 
} 
  
// A standard function to extract 
// minimum value node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
  
{ 
  
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] 
        = minHeap->array[minHeap->size - 1]; 
  
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return temp; 
} 
  
// A utility function to insert 
// a new node to Min Heap 
void insertMinHeap(struct MinHeap* minHeap, 
                   struct MinHeapNode* minHeapNode) 
  
{ 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 
  
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    minHeap->array[i] = minHeapNode; 
} 
  
// A standard function to build min heap 
void buildMinHeap(struct MinHeap* minHeap) 
  
{ 
  
    int n = minHeap->size - 1; 
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
} 
  
// A utility function to print an array of size n 
void printArr(int arr[], int n,char c) 
{ 
     str[k].key= c;
   
    int i; 
    char temp;
    char storeLetter[100]={0};
    
    for (i = 0; i < n; ++i) 
{
        printf("%d", arr[i]); 

      //first covert int to temp string then append global string with temp string
        temp = arr[i] +'0'; //converting int to string
        //strcat(storeLetter,temp);
        // printf("%c",temp);
        strncat(storeLetter, &temp, 1); 
        


}
strcat(str[k].value,storeLetter);
k++;
  
    printf("\n"); 
//printf("\nHELL %s\n",storeLetter);

    
} 
  
// Utility function to check if this node is leaf 
int isLeaf(struct MinHeapNode* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
} 
  
// Creates a min heap of capacity 
// equal to size and inserts all character of 
// data[] in min heap. Initially size of 
// min heap is equal to capacity 
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
  
{ 
  
    struct MinHeap* minHeap = createMinHeap(size); 
  
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
  
    minHeap->size = size; 
    buildMinHeap(minHeap); 
  
    return minHeap; 
} 
  
// The main function that builds Huffman tree 
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
  
{ 
    struct MinHeapNode *left, *right, *top; 
  
    // Step 1: Create a min heap of capacity 
    // equal to size.  Initially, there are 
    // modes equal to size. 
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
  
    // Iterate while size of heap doesn't become 1 
    while (!isSizeOne(minHeap)) { 
  
        // Step 2: Extract the two minimum 
        // freq items from min heap 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
  
        // Step 3:  Create a new internal 
        // node with frequency equal to the 
        // sum of the two nodes frequencies. 
        // Make the two extracted node as 
        // left and right children of this new node. 
        // Add this node to the min heap 
        // '$' is a special value for internal nodes, not used 
        top = newNode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        insertMinHeap(minHeap, top); 
    } 
  
    // Step 4: The remaining node is the 
    // root node and the tree is complete. 
    return extractMin(minHeap); 
} 
  
// Prints huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 
void printCodes(struct MinHeapNode* root, int arr[], int top) 
  
{ 
  
    // Assign 0 to left edge and recur 
    if (root->left) { 
  
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1); 
    } 
  
    // Assign 1 to right edge and recur 
    if (root->right) { 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    } 
  
    // If this is a leaf node, then 
    // it contains one of the input 
    // characters, print the character 
    // and its code from arr[] 
    if (isLeaf(root)) { 
     use_decom++;
        printf("%c: ", root->data); 
       char send_key = root->data;
        printArr(arr, top,send_key); 
    } 
} 
  
// The main function that builds a 
// Huffman Tree and print codes by traversing 
// the built Huffman Tree 
void HuffmanCodes(char data[], int freq[], int size) 
  
{ 
    // Construct Huffman Tree 
    struct MinHeapNode* root 
        = buildHuffmanTree(data, freq, size); 
  
    // Print Huffman codes using 
    // the Huffman tree built above 
    int arr[MAX_TREE_HT], top = 0; 
  
    printCodes(root, arr, top); 
} 
  void huffmanMain()
{
	 
 
     
  //char str1[1000]={0};
   //fgets(str1,1024,stdin);
  	bzero(str1,100);
  	bzero(str->msgg,100);
	bzero(str->value,100);
    	char msg[100]={0};
    
  	printf("\n Please Enter any String");
  	scanf ("%[^\n]%*c", str1);
  	
  	strcpy(buffer,str1);
  	strcat(msg,str1);
int i, j, k;	
  	for(i = 0; i < strlen(str1); i++)
  	{
  		for(j = i + 1; str1[j] != '\0'; j++)
  		{
  			if(str1[j] == str1[i])  
			{
  				for(k = j; str1[k] != '\0'; k++)
				{
					str1[k] = str1[k + 1];
				}
 			}
		}
	}
	
 
	int size = findSize(str1);// findsize return size of string
//use_decomsg_size = size;
      //this portion of code find frequency of character in string 
	int freq[size];
	int count =0;
	//printf("\n%d",size);
for(i =0;str1[i]!='\0';i++)
{
count =0;
for(j=0;msg[j]!='\0';j++)
{
if(str1[i]==msg[j])
{
count++;
			}
}
freq[i]=count;
	}
//---end
		
    HuffmanCodes(str1, freq, size); 



int y =0;
//this portion of code assign huffman code to original_msg
 for(i =0;i<msg[i]!='\0';i++)
{
char c = msg[i];
for(k=0;k<size;k++)
{
char l = str[k].key;
if(c==l)
{
 //printf("\n%s\n", str[k].value);    
//char abc[10] = {0};
strcpy(str[y].msgg ,str[k].value);
use_decomsg_size++;
y++;
 strcat(decompress_string,str[k].value);
}
}
}
//----end 

printf("%s",decompress_string);//display decompress string
    //return decompress_string; 


}
/*
void compress()
{

huffmanMain();
decompress_msg(decompress_string);
//decompress_msg( decompress_string);

}
*/


//Function for error
void error(const char *msg)
{
		perror(msg);  //interprates the error num and o/p the error disciption
		exit(1); //if any error then terminate the program
		
		

}

int main(int argc, char* argv[]) //using comand line argument
{//argc is num of agrument
 //1. file name
 //2. port num
 //argv contains original value of parameter
 	if(argc<2)
	 {
 		fprintf(stderr,"Port num not provided\n");
 		exit(1);
 		
	 }
	 int sockfd, newsockfd,port_num,valread,valwrite;  //socket file discriptor, new socket file discriptor,
	
	 struct sockaddr_in serv_addr; 
	 socklen_t clilen; 
	 struct hostent *server;
	 
	 //creating socket
	 
	 sockfd =socket(AF_INET, SOCK_STREAM, 0);
	 if(sockfd<0)
	 {
	 	 perror("[+]Socket failed...");
	 	  return -1;
	 }
	 
	 server=gethostbyname(argv[1]);
	 bzero((char *) &serv_addr, sizeof(serv_addr));
	 port_num=atoi(argv[1]);
	 serv_addr.sin_family = AF_INET;  
    	 serv_addr.sin_port = htons( port_num ); 
    
    	 if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
   	 { 
      	  printf("\nInvalid address/ Address not supported \n"); 
      	  return -1; 
         } 
    
    
   	 if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    	{ 
     	   printf("\nConnection Failed \n"); 
      	  return -1; 
    	} 
  
  
  //Code for write messages
  
    printf("##### Welcome to CryptCom #####\n");
     printf("\n*** You are in server side ***\n");
     printf(" Type 'exit' to terminate\n");
    
    while(1)
    {
    	 bzero(buffer,1024);
    	 printf("Client (type): " );
    	// fgets(buffer,1024,stdin);
    	 printf("%s",buffer);
    	 huffmanMain();
    	 decompress_msg(decompress_string);
    	 valwrite = write( sockfd , buffer, strlen(buffer));
    	 if(valwrite<0)
  	   {
     		error("[+]Error on writing..\n"); 
     	   }
     	   bzero(buffer,1024);
   	 valread = read(sockfd , buffer, 1024); 
   	
   	/* if(strcmp(buffer,"exit") == 0)
   	 {
   	 	printf("Server terninated\n");
   	 	break;
   	 }
   	 */
   	 printf("Server: %s",buffer );
   	 if(strncmp("exit",buffer,4)==0)
    	 break;
    	 bzero(buffer,1024);
   	 
   	 
    	
    }
    close(sockfd);
    close(newsockfd);
    return 0; 
    
}
	 			
