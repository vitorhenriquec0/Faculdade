#include <stdio.h>

int main() {
    
    int anos=0;
    
    int anacleto=150, felisberto=110;
    
    int anacleto_cresc=2, felisberto_cresc=3;
    
    while (felisberto <= anacleto) {
        anacleto += anacleto_cresc;
        felisberto += felisberto_cresc;
        anos++;
    }
    
    printf("Felisberto sera mais alto que Anacleto em %d anos.\n", anos);
    
    return 0;
}