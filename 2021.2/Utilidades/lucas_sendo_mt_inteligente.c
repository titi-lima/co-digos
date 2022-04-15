#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[20];
    float salario;
} Funcionario;

void cadastrar_funcionario(Funcionario** func) {
    *func = (Funcionario*) realloc(*func, 3*sizeof(Funcionario));
    func->id = 2;
    printf("O endereco do func[0] dentro da funcao eh %p e seu id eh %d\n", func, func[0]->id);
    func[0][1].id = 3;
    printf("O endereco do func[1] dentro da funcao eh %p e seu id eh %d\n", &func[0][1], func[0][1].id);
    func[0][2].id = 4;
    printf("O endereco do func[2] dentro da funcao eh %p e seu id eh %d\n", &func[0][2], func[0][2].id);
}

int main() {
    Funcionario *func = NULL;
    cadastrar_funcionario(&func);
    printf("O endereco do func dentro da main eh %p e seu id eh %d\n", func, func->id);
    printf("O endereco do func[1] dentro da main eh %p e seu id eh %d\n", &func[1], func[1].id);
    printf("O endereco do func[2] dentro da main eh %p e seu id eh %d\n", &func[2], func[2].id);
    free(func);
    return 0;
}
