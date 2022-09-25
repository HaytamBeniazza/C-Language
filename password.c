
int main()
{
    char password[20];

    again:
    printf("enter a password here,(not more than 20 characters).\n");
    scanf(" %s", password);
    int i=0;
    int a,b,c;
    a=b=c=0;
    for(i=0;i<20;i++)
    {
        if(isalpha(password[i]))
        {
            if(isupper(password[i]))
               {
                 a++;
               }
        }
        else if(isdigit(password[i]))
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    if((a==0)||(b==0)||(c==0))
    {
        printf("Your password is weak, please change it \n");

    }
    else{
        printf("Strong password\n");
    }
    goto again;
    return 0;
	}
