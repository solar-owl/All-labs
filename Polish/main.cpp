#include "Polish.h"

int  main()
{

    cout << "Enter your math expression: ";
    TString s;
    cin >> s;
    cout << s << " ~ ";
    TQueue<char> B;
    B = ConvertToPol(s);
    B.Print();
    cout << " = " << Rez(B) << endl;
  
  return 0;
}