// import java.util.Scanner;
// public class bellman
// {
//     private int numberofvertices;
//     private int distances[];
//     public static final int MAX_VALUE=999;

//     public bellman(int numberofvertices)
//     {
//         this.numberofvertices=numberofvertices;
//         distances = new int[numberofvertices+1];
//     }
//     public void BellmanFordEvaluation(int sourcenode,int adjacencymatrix[][])
//     {
//         for(int node=1;node<=numberofvertices;node++)
//         {
//             distances[node]=999;
//         }
//         distances[sourcenode]=0;
//         for(int node=1;node<=numberofvertices-1;node++)
//         {
//             for(int x=1;x<=numberofvertices;x++)
//             {
//                 for(int y=1;y<=numberofvertices;y++)
//                 {
//                     if(adjacencymatrix[x][y]!=999)
//                     {
//                         if(distances[y]>distances[x]+adjacencymatrix[x][y])
//                         {
//                             distances[y]=distances[x]+adjacencymatrix[x][y];
//                         }
//                     }
//                 }
//             }
//         }
        // for(int vertex=1;vertex<=numberofvertices;vertex++)
        // {
        //     System.out.println("The distance from "+sourcenode+"to"+vertex+"is"+distances[vertex]);
        // }
//     }
    // public static void main(String[] args) {
    //     int sourcenode;
    //     int numberofvertices;
    //     Scanner sc = new Scanner(System.in);
    //     numberofvertices=sc.nextInt();
    //     int adjacencymatrix[][] = new int[numberofvertices+1][numberofvertices+1];
    //     System.out.println("Enter the matrix");
    //     for(int x= 1;x<=numberofvertices;x++)
    //     {
    //         for(int y=1;y<=numberofvertices;y++)
    //         {
    //             adjacencymatrix[x][y]=sc.nextInt();
    //         }
    //     }
    //     bellman b = new bellman(numberofvertices);
    //     System.out.println("Enter the source");
    //     sourcenode=sc.nextInt();
    //     b.BellmanFordEvaluation(sourcenode,adjacencymatrix);
    // }
// }

import java.util.Scanner;
public class bellman
{
    private int numberofvertices;
    private int distances[];
    public static final int MAX_VALUE=999;
    public bellman(int numberofvertices)
    {
        this.numberofvertices=numberofvertices;
        distances=new int[numberofvertices+1];
    }
    void BellmanFordEvaluation(int sourcenode,int adjacencymatrix[][])
    {
        
        for(int i=1;i<=numberofvertices;i++)
        {
            distances[i]=999;
        }
        distances[sourcenode]=0;
        for(int node=1;node<=numberofvertices-1;node++)
        {
            for(int x=1;x<=numberofvertices;x++)
            {
                for(int y=1;y<=numberofvertices;y++)
                {
                    if(adjacencymatrix[x][y]!=999)
                    {
                        if(distances[y]>distances[x]+adjacencymatrix[x][y])
                        {
                            distances[y]=distances[x]+adjacencymatrix[x][y];
                        }
                    }
                }
            }
        }
        for(int vertex=1;vertex<=numberofvertices;vertex++)
        {
            System.out.println("The distance from "+sourcenode+"to"+vertex+"is"+distances[vertex]);
        }
    }
    public static void main(String[] args) {
        int sourcenode;
        int numberofvertices;
        Scanner sc = new Scanner(System.in);
        numberofvertices=sc.nextInt();
        int adjacencymatrix[][] = new int[numberofvertices+1][numberofvertices+1];
        System.out.println("Enter the matrix");
        for(int x= 1;x<=numberofvertices;x++)
        {
            for(int y=1;y<=numberofvertices;y++)
            {
                adjacencymatrix[x][y]=sc.nextInt();
            }
        }
        bellman b = new bellman(numberofvertices);
        System.out.println("Enter the source");
        sourcenode=sc.nextInt();
        b.BellmanFordEvaluation(sourcenode,adjacencymatrix);
    }
}