#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q; // itens (n), consultas (q)
    cin >> n >> q;
    
    vector<long long> p(n);
    
    // lendo os preços e guardando no vetor
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // ordenação decrescente
    sort(p.begin(), p.end(), greater<long long>());
    
    vector<long long> pref(n + 1, 0);
    
    // acumlado atual = acumulado anterior + preco do item atual
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + p[i - 1];
    }
    
    while (q--) {
        // x = total de itens escolhidos, y = qntd de itens que sairão de fraça
        int x, y;
        cin >> x >> y;
        
        //pref[x] = soma atual de todos 'x' escolhidos
        // pref[x-y] = soma dos itens que serão pagos (os mais caros)
        // ao subtrair os 2, sobra o valor dos itens gratuitos
        long long resultado = pref[x] - pref[x - y];
        
        cout << resultado << endl;
    }
    
    return 0;
}