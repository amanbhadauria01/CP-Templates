// comparison function
bool cmp(const cl & a, const cl & b){
    return (a.e < b.e);
}
// compairson syntax
upper_bound(v.begin(),v.end(),value,cmp);