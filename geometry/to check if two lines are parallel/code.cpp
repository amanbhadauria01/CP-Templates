class pt{
    public :
    int x, y;
};

// the two lines are a1--->a2 , b1--->b2
// multiplying helps as we dont have to take care of divide by 0

bool parallel(pt a1, pt a2 , pt b1 , pt b2){
    return (a1.x-a2.x)*(b1.y-b2.y) == (a1.y-a2.y)*(b1.x-b2.x);
}