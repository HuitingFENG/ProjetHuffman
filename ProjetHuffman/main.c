int main(){
    Input2Binary("C:\\Projet Huffman\\Test Files\\Alice_input.txt","C:\\Projet Huffman\\Test Files\\Alice_binary.txt");
    printf("End of conversion !\n");
    printf("Input : %d\n", compter("C:\\Projet Huffman\\Test Files\\Alice_input.txt"));
    printf("Binary : %d\n", compter("C:\\Projet Huffman\\Test Files\\Alice_binary.txt"));
    struct HuffNode* L=list_occurrences("C:\\Projet Huffman\\Test Files\\Alice_input.txt");
    struct HuffNode* tree=createTree(L);
    printf("Huffman encode (le dictionnaire de Huffman): \n");
    write_dictonnaire(L);
    printf("finir!");
    return 0;
}
