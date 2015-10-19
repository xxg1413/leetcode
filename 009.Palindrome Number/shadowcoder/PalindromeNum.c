bool isy(int x) {  
    int y = 0;  
    int origin = x;
    if (x < 0) return 0;
    while(x != 0) {  
        y = y * 10 + x % 10;  
        x /= 10;  
    }  
  
    return y == origin ;  
}
