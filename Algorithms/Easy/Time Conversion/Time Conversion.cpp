#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    string hora_texto = s.substr(0, 2);
    string resto_hora = s.substr(2, 6);
    string formato = s.substr(8, 2);

    int hora_num = stoi(hora_texto);

    if (formato == "AM") {
        if (hora_num == 12) {
            hora_texto = "00";
        }
    } 
    else {
        if (hora_num != 12) {
            hora_num = hora_num + 12;
            hora_texto = to_string(hora_num);
        }
    }

    return hora_texto + resto_hora;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
