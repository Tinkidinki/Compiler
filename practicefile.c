
int printf(const char *format, ...); 

int add(int a, int b){
        return a + b;
    }


int main(){
    int x;
    int y;
    int a;

    x = 0;
    y = 7;
    
    if (x < y){
        printf("if\n");
    }
    else {
        printf("else\n");
    }

    a = add(3,5);



}
