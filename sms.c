#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char* product_format_out = "%d\t%s\t%.2f\t%d\n";
const char* product_format_in = "%d %s %f %d";

struct node{
    char p_name[50];
    int p_code;
    float rate;
    int p_amount;
    struct node*next;
};

struct sell{
    char s_name[50];
    int s_code;
    float price;
    int s_amount;
};

struct sell *ptr,*ptr1,*ptr2;
struct node *sell_head = NULL;
struct node *head = NULL;
int fixt = 0,total_sell_p = 0;
void display();
FILE *fp;

void ReadfromDatabase()
{
    struct  node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp=head;

    fp= fopen("products.txt","r");
    if(fp == NULL){
        printf("Error: File can't load\n");
    }
    else
    {
        printf("File successfully opened to read data!\n");
        char p_name[50];
        int p_code;
        float rate;
        int p_amount;
        while(fscanf(fp,product_format_in,&p_code,p_name,&rate,&p_amount)!=EOF)
        {
            if(tmp==NULL){
                tmp=(struct node*)malloc(sizeof(struct node));
                tmp->p_code= p_code;
                strcpy(tmp->p_name,p_name);
                tmp->rate= rate;
                tmp->p_amount= p_amount;
                tmp->next = NULL;
                head = tmp;
                }
            else
            {
                tmp=head;
                struct  node *N_tmp;
                N_tmp=(struct node*)malloc(sizeof(struct node));
                while (tmp->p_code != p_code && tmp->next !=NULL)
                {
                    tmp=tmp->next;
                }
                if(tmp->p_code != p_code)
                {
                    N_tmp->p_code= p_code;
                    strcpy(N_tmp->p_name,p_name);
                    N_tmp->rate= rate;
                    N_tmp->p_amount= p_amount;
                    N_tmp->next = NULL;
                    tmp->next= N_tmp;
                }
                else
                {
                    printf("This product is already in the list.\n");
                } 
            } 
        }
    }    
}

void Writetodatabase()
{
    fp= fopen("products.txt","a");
    if(fp == NULL){
        printf("Error: File can't load\n");
    }
    else{
        struct node *tmp1 = head;
        while(tmp1!=NULL){
            fprintf(fp,product_format_out,tmp1->p_code,tmp1->p_name,tmp1->rate,tmp1->p_amount);
            tmp1 = tmp1->next;
        }
        fclose(fp);
    }
    display();
}

void view_products()
{
    ReadfromDatabase();
    struct node *tmp1 = head;
    printf("\t\t\tProduct Code\tProduct Name\tPrice\tProduct amount\n");
    while(tmp1!=NULL){
        printf("\t\t\t   %d",tmp1->p_code);
        printf("\t\t%s",tmp1->p_name);
        printf("\t\t%.2f",tmp1->rate);
        printf("\t\t%d\n\n",tmp1->p_amount);
        tmp1 = tmp1->next;
    }
    printf("\n\n\n");
    display();
}

void top_position()
{
    struct node*tmp;
    tmp = malloc(sizeof(struct node));
    printf("Enter product code : ");
    scanf("%d",&tmp->p_code);
    printf("Enter product name : ");
    scanf("%s",tmp->p_name);
    printf("Enter product price : ");
    scanf("%f",&tmp->rate);
    printf("Enter product amount : ");
    scanf("%d",&tmp->p_amount);
    tmp->next = head;
    head = tmp;
}

void any_position()
{

    int n;
    printf("Enter product position number : ");
    scanf("%d",&n);

    if(n==1)
        top_position();
    else{
        struct node*newnode,*tmp1;
        newnode = malloc(sizeof(struct node));
        tmp1 = malloc(sizeof(struct node));

        tmp1 = head;

        printf("Enter product code : ");
        scanf("%d",&newnode->p_code);
        printf("Enter product name : ");
        scanf("%s",newnode->p_name);
        printf("Enter product price : ");
        scanf("%f",&newnode->rate);
        printf("Enter product amount : ");
        scanf("%d",&newnode->p_amount);

        for(int i =2; i<=n-1; i++){
            tmp1 = tmp1->next;
        }

        newnode->next = tmp1->next;
        tmp1->next = newnode;
    }

}

void last_position()
{
    struct node*newnode,*tmp1;
    newnode = malloc(sizeof(struct node));
    tmp1 = malloc(sizeof(struct node));

    tmp1 = head;

    printf("Enter product code : ");
    scanf("%d",&newnode->p_code);
    printf("Enter product name : ");
    scanf("%s",newnode->p_name);
    printf("Enter product price : ");
    scanf("%f",&newnode->rate);
    printf("Enter product amount : ");
    scanf("%d",&newnode->p_amount);

    while (tmp1->next!=NULL)
        tmp1 = tmp1->next;

    tmp1->next = newnode;

}

void create_products()
{
    printf("\t\t\t\t------------------------------------------------\n");
    printf("\t\t\t\t| Which position you want to add your product? |\n");
    printf("\t\t\t\t------------------------------------------------\n");
    printf("\t\t\t\t\t\t  1.Top position.\n");
    printf("\t\t\t\t\t\t  2.Any position that you want.\n");
    printf("\t\t\t\t\t\t  3.Last position.\n\n");

    printf("\n Choose an option [1-3] : ");
    int num;
    scanf("%d",&num);
    if(num==1)
        top_position();
    else if(num==2)
        any_position();
    else if(num==3)
        last_position();

    display();

}

void del_products()
{
    ReadfromDatabase();
    int code;
    printf("Enter product code : ");
    scanf("%d",&code);

    struct node*newnode,*tmp;
    newnode = malloc(sizeof(struct node));
    tmp = malloc(sizeof(struct node));

    tmp = head;
    int count = 0;
    while(tmp->p_code!=code){
        tmp = tmp->next;
        count++;
    }

    if(count==0){
        head = tmp->next;
        free(tmp);
    }
    else{
        tmp = head;
        for(int i =2; i<=count; i++){
            tmp = tmp->next;
        }

        newnode->next = tmp->next->next;
        free(tmp->next);
        tmp->next = newnode->next;
    }


    display();
}

void old_product()
{
    ReadfromDatabase();
    int code = 0, amount = 0;
    printf("Enter product code : ");
    scanf("%d",&code);

    struct node*tmp;
    //newnode = malloc(sizeof(struct node));
    tmp = malloc(sizeof(struct node));

    tmp = head;
    //int count = 0;
    while(tmp->p_code!=code){
        tmp = tmp->next;
        //count++;
    }

    printf("Enter product amount : ");
    scanf("%d",&amount);

    tmp->p_amount +=amount;

    display();
}

void up_price(){
    
    ReadfromDatabase();
    int code = 0, price = 0;
    printf("Enter product code : ");
    scanf("%d",&code);

    struct node*tmp;
    //newnode = malloc(sizeof(struct node));
    tmp = malloc(sizeof(struct node));

    tmp = head;
    //int count = 0;
    while(tmp->p_code!=code){
        tmp = tmp->next;
        //count++;
    }

    printf("Enter new price : ");
    scanf("%d",&price);

    tmp->rate = price;

    display();
}

void products()
{

    printf("\t\t\t\t\t----------------------------\n");
    printf("\t\t\t\t\t|         Products         |\n");
    printf("\t\t\t\t\t----------------------------\n");
    printf("\t\t\t\t\t| 1.View Products          |\n");
    printf("\t\t\t\t\t| 2.Enter New Product      |\n");
    printf("\t\t\t\t\t| 3.Delete Product         |\n");
    printf("\t\t\t\t\t| 4.Add Old Product amount |\n");
    printf("\t\t\t\t\t| 5.Update Product price   |\n");
    printf("\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t----------------------------\n");


    printf("\n Choose an option [1-5] : ");
    int num;
    scanf("%d",&num);
    if(num==1)
        view_products();
    else if(num==2)
        create_products();
    else if(num==3)
        del_products();
    else if (num==4)
        old_product();
    else if(num==5)
        up_price();
}

void most_sell_p()
{
    ReadfromDatabase();
    int tmp = 0,count = 0,i;
    for(i = 0; i < fixt; i++){
        tmp = (ptr+i)->s_amount;
        for(int j = i+1; j<fixt; j++){
            if((ptr+i)->s_code == (ptr+j)->s_code){
                tmp += (ptr+j)->s_amount;
            }
        }
        strcpy((ptr1+i)->s_name,(ptr+i)->s_name);
        (ptr1+i)->s_code = (ptr+i)->s_code;
        (ptr1+i)->s_amount = tmp;
        count++;
    }

    for(i = 0; i<count; i++){
        for(int j = i+1; j<count; j++){
            if((ptr1+i)->s_amount < (ptr1+j)->s_amount && i+1<count){

              strcpy((ptr2)->s_name,(ptr1+j)->s_name);
              (ptr2)->s_code = (ptr1+j)->s_code;
              (ptr2)->s_amount = (ptr1+j)->s_amount;

              strcpy((ptr1+i)->s_name,(ptr1+j)->s_name);
              (ptr1+i)->s_code = (ptr1+j)->s_code;
              (ptr1+i)->s_amount = (ptr1+j)->s_amount;

              strcpy((ptr1+j)->s_name,(ptr2)->s_name);
              (ptr1+j)->s_code = (ptr2)->s_code;
              (ptr1+j)->s_amount = (ptr2)->s_amount;

            }
        }
    }


    i = 0;
    printf("\t\t\t\t\t--------------------------\n");
    printf("\t\t\t\t\t|    Most sold product   |\n");
    printf("\t\t\t\t\t--------------------------\n\n");
    printf("\t\tProduct code\tProduc name\t Amount\n\n\n");

    printf("\t\t   %d\t\t  %s\t\t %d\n\n",(ptr1+i)->s_code,(ptr1+i)->s_name,(ptr1+i)->s_amount);

    display();

}

void sells()
{


    printf("\t\t\t\t\t--------------------------\n");
    printf("\t\t\t\t\t|          Sells         |\n");
    printf("\t\t\t\t\t--------------------------\n");
    printf("\t\t\t\t\t| 1.Total Sells          |\n");
    printf("\t\t\t\t\t| 2.Sold product details |\n");
    printf("\t\t\t\t\t| 3.Most sold product    |\n");
    printf("\t\t\t\t\t|                        |\n");
    printf("\t\t\t\t\t--------------------------\n");


    printf("\n Choose an option [1-3] : ");
    int num;
    scanf("%d",&num);
    if(num==1){

        printf("\t\t\t\t\t Till now %d have been sold \n",total_sell_p);

    }
    else if(num==2){

        printf("\t\t\t\t\t--------------------------\n");
        printf("\t\t\t\t\t| Sold products details  |\n");
        printf("\t\t\t\t\t--------------------------\n\n");
        printf("\t\tProduct code\tProduc name\t Amount\t\tPrice\n\n");
        for(int i = 0; i < fixt; i++){

            printf("\t\t   %d\t\t  %s\t\t %d\t\t %.2f\n\n",(ptr+i)->s_code,(ptr+i)->s_name,(ptr+i)->s_amount,(ptr+i)->price);
        }
    }
    else if(num==3)
        most_sell_p();


    display();
}

void calculate()
{
      ReadfromDatabase();
      struct node*newnode,*tmp;
      newnode = malloc(sizeof(struct node));
      tmp = malloc(sizeof(struct node));
      //tmp1 = malloc(sizeof(struct node));

      int num_p,amount,temp=0,fixt1 = fixt;
      float sum = 0;
      printf("\t\t\t\t\t Enter number of products : ");
      scanf("%d",&num_p);


      for(int i = 0; i < num_p; i++){

        amount = 0;
        printf("Enter product code : ");
        scanf("%d",&newnode->p_code);
        printf("Enter product amount : ");
        scanf("%d",&amount);

         tmp = head;
         //int count = 0;
          while(newnode->p_code!=tmp->p_code){
              tmp = tmp->next;
              //count++;
          }
          tmp->p_amount = tmp->p_amount - amount;

          temp = tmp->rate*amount;
          sum += temp;
          //sum *= amount;


          strcpy((ptr+fixt)->s_name,tmp->p_name);
          (ptr+fixt)->s_code = tmp->p_code;
          (ptr+fixt)->price = tmp->rate;
          (ptr+fixt)->s_amount += amount;
          fixt++;

          total_sell_p +=amount;

          //tmp1 = sell_head;
          //tmp1->next = tmp->next;

          free(newnode);
      }

      printf("\t\t\t\t\t--------------------------\n");
      printf("\t\t\t\t\t|       Total bill       |\n");
      printf("\t\t\t\t\t--------------------------\n\n");
      printf("\t\tProduct code\tProduc name\t Amount\t\tPrice\n\n");

      for(int i = fixt1; i < fixt; i++){

          printf("\t\t   %d\t\t  %s\t\t %d\t\t %.2f\n\n",(ptr+i)->s_code,(ptr+i)->s_name,(ptr+i)->s_amount,(ptr+i)->price);
      }
      printf("\t\t\t\t\t--------------------------------------\n\n");
      printf("\t\t\t\t\tTotal amount = %.2f Taka Only\n\n",sum);
      printf("\n\n\n");


      display();
}


void sub_menu()
{
  
    int num;
    printf("\n Choose an option [1-5] : ");
    scanf("%d",&num);
    if(num==1)
        products();
    else if(num==2)
        sells();
    else if(num==3)
        calculate();
    else if(num==4)
        Writetodatabase();
    else if(num==5){
        printf("\t\t\tThank you so much.For using SMS.\n");
        return;
    }
}


void main_menu()
{

    printf("\t\t\t\t\t* * * * * * * *\t\t\t\n");
    printf("\t\t\t\t\t*             *\t\t\t\n");
    printf("\t\t\t\t\t*  Pure Souls *\t\t\t\n");
    printf("\t\t\t\t\t*             *\t\t\t\n");
    printf("\t\t\t\t\t* * * * * * * *\t\t\t\n");

    int password,tmp = 3170;
    char user_id[20],tmp1[20] = "mamun3170",tamp;

    error:{
        printf("User id : ");
        scanf("%s",user_id);
        scanf("%c",&tamp);
        printf("Password : ");
        scanf("%d",&password);
    }

    int res = strcmp(tmp1,user_id);

    if(tmp == password && res==0){
        display();
    }
    else{
        printf("Please enter correct user id and password\n");
        goto error;
    }

}

void display()
{

    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t|         Menu        |\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t| 1.Products          |\n");
    printf("\t\t\t\t\t| 2.Sells             |\n");
    printf("\t\t\t\t\t| 3.Calculate bill    |\n");
    printf("\t\t\t\t\t| 4.Save to database  |\n");
    printf("\t\t\t\t\t| 5.Log Out           |\n");
    printf("\t\t\t\t\t|                     |\n");
    printf("\t\t\t\t\t-----------------------\n");

    sub_menu();

}

int main()
{

    main_menu();
    return 0;

}