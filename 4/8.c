#include <stdio.h>
#define int long long

int main(){
    int kings, rooms;
    scanf("%lld %lld", &kings, &rooms);
    int max = kings-rooms+1;
    max = (max * (max-1))/2;
    int mod = kings%rooms;
    int quo = kings/rooms;
    int a = (quo*(quo+1))/2;
    int b = (quo*(quo-1))/2;
    int min = mod*a + (rooms-mod)*b;
    printf("%lld %lld", max, min);
    
}
