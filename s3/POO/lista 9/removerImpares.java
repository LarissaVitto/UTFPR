static ArrayList<Integer> removerImpares(ArrayList<Integer> numeros) {
    for (int i = 0; i < numeros.size(); i++) {
        if (numeros.get(i) % 2 != 0) {
            numeros.remove(i);
            i--;
        }
    }
    return numeros;
}