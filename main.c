#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char titulo[60]; 
    int ano;
    char genero[20];
    float nota;
} Filme;


void title_case(char *s) {
    if (s == NULL || *s == '\0') return;

    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 32;
    }
}

void sugerir_filme(Filme lista_filmes[], int tamanho_lista) {
    char genero_escolhido[20];
    
    Filme *filmes_filtrados[tamanho_lista]; 
    int contador_filtrados = 0;
    int indice_sorteado;

    printf("Sugestão de Filmes IMDb\n");
    printf("Gêneros disponíveis: Drama, Crime, Ação, Fantasia, Ficção Científica, Comédia, Terror\n");
    
    printf("\nQual gênero você gostaria de assistir? ");
    scanf("%19s", genero_escolhido);

    title_case(genero_escolhido);

    for (int i = 0; i < tamanho_lista; i++) {
       
        if (strcmp(lista_filmes[i].genero, genero_escolhido) == 0) {
            
            filmes_filtrados[contador_filtrados] = &lista_filmes[i];
            contador_filtrados++;
        }
    }

    if (contador_filtrados == 0) {
        printf("\n😔 Não encontrei filmes de '%s' nesta lista.\n", genero_escolhido);
        printf("Tente um dos gêneros disponíveis acima.\n");
        return;
    }

    
    static int inicializado = 0;
    if (!inicializado) {
        srand(time(NULL)); 
        inicializado = 1;
    }
    
    
    indice_sorteado = rand() % contador_filtrados; 

    Filme *filme_sugerido = filmes_filtrados[indice_sorteado];

   
    printf("\n✅ Sugestão de Filme:\n");
    printf("  Título: %s\n", filme_sugerido->titulo);
    printf("  Ano: %d\n", filme_sugerido->ano);
    printf("  Gênero: %s\n", filme_sugerido->genero);
    printf("  Nota IMDb (simulada): %.1f\n", filme_sugerido->nota);
    printf("\nBoa sessão!\n");
}

int main() {
    // lista dos filmes (dados fixos)
    Filme filmes[] = {
        {"Um Sonho de Liberdade", 1994, "Drama", 9.3},
        {"O Poderoso Chefão", 1972, "Crime", 9.2},
        {"Batman: O Cavaleiro das Trevas", 2008, "Ação", 9.0},
        {"Pulp Fiction: Tempo de Violência", 1994, "Crime", 8.9},
        {"A Lista de Schindler", 1993, "Drama", 9.0},
        {"O Senhor dos Anéis: O Retorno do Rei", 2003, "Fantasia", 8.9},
        {"Interestelar", 2014, "Ficção Científica", 8.6},
        {"A Origem", 2010, "Ficção Científica", 8.8},
        {"Forrest Gump: O Contador de Histórias", 1994, "Drama", 8.8},
        {"Clube da Luta", 1999, "Drama", 8.8},
        {"Matrix", 1999, "Ficção Científica", 8.7},
        {"Parasita", 2019, "Drama", 8.5},
        {"A Viagem de Chihiro", 2001, "Fantasia", 8.6},
        {"O Silêncio dos Inocentes", 1991, "Terror", 8.6},
        {"Psicose", 1960, "Terror", 8.5},
        {"O Show de Truman", 1998, "Comédia", 8.2},
        {"Curtindo a Vida Adoidado", 1986, "Comédia", 7.8},
        {"Vingadores: Ultimato", 2019, "Ação", 8.4},
        {"Gladiador", 2000, "Ação", 8.5}
    };

    int tamanho = sizeof(filmes) / sizeof(filmes[0]);

    sugerir_filme(filmes, tamanho);

    return 0;
}
