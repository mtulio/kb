#include <stdio.h>
#include <windows.h>

int main(VOID)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    //aloca memoria
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    
    //cria processo filho
    if(!CreateProcess(NULL, //usa linha de comando 
    "C:\\WINDOWS\\system32\\mstsc.exe /console", // linha de comandos
    NULL, //nao herda descritor de processo
    NULL, // nao herdadescritor de thread
    FALSE, // desativa herança de descritor
    0, // nenhum flag de criacao
    NULL, //usa o bloco de ambiente do pai
    NULL, // usa diretorio existente do pai
    &si,
    &pi))
    {
         fprintf(stderr, "Falha ao criar processo [CreateProcess()]");
         return -1;
    }
    // pai esperara que o filho termine
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Filho terminou a tarefa");
    
    //fecha descritores
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    getchar();getchar();
}
    
