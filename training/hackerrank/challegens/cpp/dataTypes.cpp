#include <iostream>
#include <cstdio>
using namespace std;

/* https://www.hackerrank.com/challenges/c-tutorial-basic-data-types
 * INPUT tests:
 * 3 444 12345678912345 a 334.23 14049.30493
 * 211916801 452082285 97592151379235457 p 19856.992 -5279235.721231465
 * 368252310 926019709 27547295356575738 c 46886.25 -247884.49188525788
 * 458873627 670540352 37274594125879112 g -79720.555 7441739.542437971
 */
int main() {

    int A;
    long B;
    long long C;
    char str;
    float D;
    double E;
    cin>>A>>B>>C>>str>>D>>E;
    //cout<<A<<"\n"<<B<<"\n";
    printf("%d\n", A);
    printf("%ld\n", B);
    printf("%lld\n", C);
    //cout<<"\n"<<str<<"\n"<<D<<"\n";
    cout<<str<<"\n";
    printf("%f\n", D);
    printf("%lf\n", E);
    return 0;
}

