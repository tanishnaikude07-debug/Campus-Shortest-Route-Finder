#include <stdio.h>

#define MAX 20
#define INF 9999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];
char name[MAX][30];

int n, source;

void inputGraph()
{
    int i, j;

    printf("Enter number of locations: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter location %d: ", i + 1);
        scanf(" %[^\n]", name[i]);
    }

    printf("\nEnter distances between locations:\n");
    printf("Enter 0 if there is no direct road.\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                printf("%s to %s: ", name[i], name[j]);
                scanf("%d", &graph[i][j]);

                if(graph[i][j] == 0)
                    graph[i][j] = INF;
            }
        }
    }
}

void displayGraph(){
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(graph[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(){
    int i, j, min, u;

    for(i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0;
    for(i = 0; i < n - 1; i++){
        min = INF;
        u = -1;
        for(j = 0; j < n; j++){
            if(visited[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        visited[u] = 1;
        for(j = 0; j < n; j++){
            if(visited[j] == 0 && graph[u][j] != INF && dist[u] + graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
}

void printPath(int v){
    if(v == source){
        printf("%s", name[v]);
        return;
    }
    if(parent[v] == -1){
        printf("No Path");
        return;
    }
    printPath(parent[v]);
    printf(" -> %s", name[v]);
}

void displayResult(){
    int i;
    dijkstra();
    printf("\nShortest paths from %s:\n\n", name[source]);
    printf("Destination\tDistance\tPath\n");
    for(i = 0; i < n; i++){
        if(i == source)
            continue;
        printf("%s\t\t", name[i]);
        if(dist[i] == INF){
            printf("INF\t\tNo Path\n");
        }
        else{
            printf("%d\t\t", dist[i]);
            printPath(i);
            printf("\n");
        }
    }
}

int main(){
    int choice, s;
    do{
        printf("\n\n--- Campus Shortest Route Finder ---\n");
        printf("1. Enter Campus Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Select Source Location\n");
        printf("4. Find Shortest Distance\n");
        printf("5. Display Shortest Paths\n");
        printf("6. Display Distance from Source\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                inputGraph();
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("\nLocations:\n");
                for(int i = 0; i < n; i++)
                    printf("%d. %s\n", i + 1, name[i]);
                printf("Enter source number: ");
                scanf("%d", &s);
                if(s >= 1 && s <= n){
                    source = s - 1;
                    printf("Source selected: %s\n", name[source]);
                }
                else{
                    printf("Invalid source.\n");
                }
                break;
            case 4:
                dijkstra();
                printf("\nShortest distances calculated successfully.\n");
                break;
            case 5:
                displayResult();
                break;
            case 6:
                dijkstra();
                printf("\nDistance from %s:\n", name[source]);
                for(int i = 0; i < n; i++){
                    if(dist[i] == INF)
                        printf("%s : No Path\n", name[i]);
                    else
                        printf("%s : %d\n", name[i], dist[i]);
                }
                break;
            case 7:
                printf("Program ended.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 7);
    return 0;
}
