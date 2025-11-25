# Como executar no WSL

Para usar este projeto no WSL (Windows Subsystem for Linux):

## 1. Acesse o WSL
```bash
wsl
```

## 2. Navegue até o diretório
```bash
cd /mnt/c/Users/jhsvn/dev/dsa-academus/c_c++/dsa-2/back-to-the-future
```

## 3. Execute o script
```bash
bash compilar-e-testar.sh
```

## Alternativa: Comando direto do PowerShell
```powershell
wsl -- bash -c "cd /mnt/c/Users/jhsvn/dev/dsa-academus/c_c++/dsa-2/back-to-the-future && bash compilar-e-testar.sh"
```

O script irá:
- ✅ Verificar GCC instalado
- ✅ Compilar com flags otimizadas
- ✅ Executar casos de teste
- ✅ Comparar resultados automaticamente
- ✅ Mostrar análise dos resultados