# Inserción Binaria vs Cycle Sort.

Este repositorio contiene el proyecto de la primera Unidad de Programacion Avanzada, el cual fue la implementación experimental y comparativa entre los algoritmos **Binary Insertion Sort** y **Cycle Sort**, desarrollada como parte del estudio de ordenamiento y análisis de rendimiento algorítmico.

## Descripción del proyecto

El objetivo principal del proyecto es comparar **Binary Insertion Sort** y **Cycle Sort** bajo distintos patrones de entrada y tamaños de muestra, analizando:
- Rendimiento temporal (en milisegundos, alta resolución con `std::chrono::steady_clock`)
- Número de comparaciones, escrituras e intercambios
- Profundidad de recursión (si aplica)
- Estabilidad y complejidad teórica

## ⚙️ Metodología
1. **Lenguaje y entorno:** C++ (compilado con g++ 13.2.0)  
2. **Plataforma:** Windows 10, CPU Intel i5, 8GB RAM  
3. **Patrón de entrada:** Aleatorio uniforme  
4. **Tamaño de entrada:** N = 1,000 / 10,000 / 100,000  
5. **Número de repeticiones:** 30 por cada tamaño de N  
6. **Métricas registradas:** Comparaciones, intercambios y tiempo total de ejecución.  
7. **Medición de tiempo:** `std::chrono::steady_clock`

## Resultados esperados

Los resultados compararán la eficiencia en:
- Tiempo promedio de ejecución
- Número de operaciones
- Comportamiento ante distintas distribuciones de entrada
- Gráficas y tablas se incluirán progresivamente en la carpeta docs/ conforme avance el análisis.
- 
## Autores

- **Cesar Jimmy Chambe Mamani**     [![GitHub](https://img.shields.io/badge/GitHub-000?style=flat&logo=github&logoColor=white)](https://github.com/KitllyCat)
- **Luis Fernando Chura Coaquira**     [![GitHub](https://img.shields.io/badge/GitHub-000?style=flat&logo=github&logoColor=white)](https://github.com/AlguienXD888)
- 
## Ejecución
El codigo se encuentra en la carpeta source y desde alli se puede compilar. Compila los algoritmos y ejecuta el programa desde la terminal:
```bash
- "g++ main.cpp -o comparacion"
- "./comparacion"
