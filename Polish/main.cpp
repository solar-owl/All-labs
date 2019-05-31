#include "Polish.h"
#include "Exception.h"

int  main()
{

    cout << "Enter your math expression: ";
    TString s;
    cin >> s;
    cout << s << " ~ ";
    TQueue<char> B;
    B = ConvertToPol(s);
    while (!B.IsEmpty())
      cout << B.Get();
    cout << " = " << Rez(B) << endl;
  
  return 0;
}