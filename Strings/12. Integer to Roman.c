char * intToRoman(int num){
    char* romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int romanValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    /* Allocate memory for the Roman numeral string */
    char* romanNumeral = (char*) malloc(16 * sizeof(char));
    memset(romanNumeral, '\0', 16 * sizeof(char));
    
    /* Convert the integer to Roman numerals */
    int i = 0;
    while (num > 0) {
        if (num >= romanValues[i]) {
            strcat(romanNumeral, romanSymbols[i]);
            num -= romanValues[i];
        } else {
            i++;
        }
    }
    
    return romanNumeral;

}
