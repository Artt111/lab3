#include <iostream>
#include <string>

// Ֆունկցիա, որը իրականացնում է տեքստի կոդավորումը 
void encrypt(std::string &text, int shift) {
    // Անցնում ենք տեքստի յուրաքանչյուր նիշի վրայով
    for (char &c : text) {
        
        c = (c + shift) % 128;  
    }
}

// Ֆունկցիա, որը կատարում է տեքստի վերծանումը 
void decrypt(std::string &text, int shift) {
    // Վերծանումը հիմնված է կոդավորման ֆունկցիայի վրա՝ 128-ից նվազեցված shift-ով
    encrypt(text, 128 - (shift % 128));
}

int main() {
    std::string text;  
    int shift;  

    
    std::cout << "Մուտքագրեք տեքստը: ";
    std::getline(std::cin, text);  

    
    std::cout << "Մուտքագրեք տեղաշարժ (1-127): ";
    std::cin >> shift;

    // Ստուգում ենք, արդյոք տեղաշարժը ճիշտ տիրույթում է
    if (shift < 1 || shift > 127) {
        std::cout << "Տեղաշարժը պետք է լինի 1-ից 127 միջև." << std::endl;
        return 1;  
    }

    
    encrypt(text, shift);
    std::cout << "Կոդավորված տեքստը: " << text << std::endl;

    
    decrypt(text, shift);
    std::cout << "Վերծանված տեքստը: " << text << std::endl;

    return 0;  
}
