
int printf(const char *format, ...); 

int main(){
    int x;
    int y;

    x = 0;
    y = 7;
    
    if (x < y){
        printf("if\n");
    }
    else {
        printf("else\n");
    }
    return 0;
}
