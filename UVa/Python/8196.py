from sys import stdin
from sys import setrecursionlimit


class Edge:

    """
    A class used to represent an edge between  u - > v with weight
    :param u: present a node with label u
    :type u: int
    :param v: present a node with label v
    :type v: int
    :param w: A flag used to print the columns to the console
        (default is False)
    :type w: int
    :returns: a edge
    :rtype: Node
    """ 
<<<<<<< HEAD
    def __init__(self,u : int ,v : int,w : int = 0):
=======
    def __init__(self,u : int ,v : int,w  = 0 : int):
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
        """            
        :param u: present a node with label u
        :type u: int
        :param v: present a node with label v
        :type v: int
        :param w: A flag used to print the columns to the console
            (default is False)
        :type w: int
        :returns: a edge
        :rtype: Node
        """        
        self.u = u
        self.v = v
        self.w = w

    def __str__(self)-> str:
        """
        :returns: a string that represent the edge between (u,v,w), u,v are nodes and w is the weigth the edge
        :rtype: str 
        """         
        return "Edge u({}) - w({})->  v:({}) ".format(self.u,self.v,self.w)     
    

class DisjoinSet:
<<<<<<< HEAD
    """
=======
     """
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
        A class used to represent an disjoin set the a graph
        :param n: represent the amount of nodes on the graph
        :type u: int
        :returns: a disjoin set
        :rtype: DisjoinSet
<<<<<<< HEAD
    """
    
=======
    """ 
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
    def __init__(self, n : int):
        """            
        :param n: represent the amount of nodes on the graph
        :type u: int
        :returns: a disjoin set
        :rtype: DisjoinSet
        """   
        self.padre = [x for x in range(n)]
        self.rank = [0 for x in range(n)]

<<<<<<< HEAD

=======
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
    def Buscar(self, x : int) -> int:
        """            
        :param x: represent the label of  the node that search its father
        :type x: int
        :returns: x's father
        :rtype: int
        """ 
        if(self.padre[x]!=x):
            self.padre[x]=self.Buscar(self.padre[x])
        return self.padre[x]

    def Union(self, x : int , y : int):
        """            
        :param x: represents the label of the node that may be attached to the tree of the node y
        :type x: int
        :param y: represents the label of the node that may be attached to the tree of the node x
        :type y: int        
        """ 
        xRaiz = self.Buscar(x)
        yRaiz = self.Buscar(y)
        if(xRaiz == yRaiz):
            return
        if self.rank[xRaiz] < self.rank[yRaiz]:
            self.padre[xRaiz] = yRaiz
        elif self.rank[xRaiz] > self.rank[yRaiz]:
            self.padre[yRaiz] = xRaiz
        else:
            self.padre[yRaiz] = xRaiz
            self.rank[xRaiz]+=1

class Node:
    """
        A class used to represent an target with weigth 
        :param to: represent the label the node
        :type to: int
        :param w: represent the weigth of u -> v
        :type w: int
    """
    def __init__(self,to : int ,w : int):
        """
        :param to: represent the label the node
        :type to: int
        :param w: represent the weigth of u -> v
        :type w: int
        """
        self.to = to
        self.w = w
    def __str__(self) -> str:
        """
        :returns: a string that represent the target and weigth the a node i-th
        :rtype: str 
        """     
        return "({},{})".format(self.to,self.w)



def kruskal(n : int, unionFind :  DisjoinSet , listEdges = list()):
<<<<<<< HEAD
    """
    :param n: represent the amount nodes in the graph
    :type n: int
    :param unionFind: represent the disjoin set of the nodes
    :type unionFind:  DisjoinSet
    :param listEdges: represent the list edge 
    :type listEdges: list of Edge 
    :returns: a int that represent the cost the minimun spaning tree  and a matriz in wich  the i-th position means  the list of node adyance the i-th node
    :rtype: int, list of list of type Nodes
    """     
    mst = 0 
=======
    mst = 0
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
    tree = [ [] for x in range(n)]
    for edgeIter in listEdges:
        e = edgeIter
        if unionFind.Buscar(e.u) != unionFind.Buscar(e.v):
            unionFind.Union(e.u,e.v)
            tree[e.u].append(Node(e.v,e.w))
            tree[e.v].append(Node(e.u,e.w))
            mst += e.w
    return mst,tree

def dfs(src : int , u  : int ,tree : list()):
  global maxEdge


  for node in tree[u]: 
    if maxEdge[src][node.to] > 0:
        continue
    maxEdge[src][node.to] = max(maxEdge[src][u],node.w) 
    dfs(src,node.to,tree)

<<<<<<< HEAD
def solve(mst, tree , cost, N):
=======
def solve():
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
    global maxEdge
    maxEdge = [ [ 0 for i in range(N)] for j in range(N)]
    for nodes,listTree in enumerate(tree):
        if listTree:
            dfs(nodes,nodes,tree)
<<<<<<< HEAD
    Queries = int(input())
    for q in range(Queries):
        u,v = map(int,input().split())
        print(mst - maxEdge[u][v] + cost[(u,v)])
    
def read_input():
    global N,M   
    lec = stdin.readline().strip()
    if not len(lec):
        return False 
    N , M = map(int,lec.split())    
    N+=1
    return True
        
def create_graph():
    global M
    listEdges = list()
    cost = dict()
    cost = dict()
    for i in range(M):
        U,V,W = map(int,input().split())
        listEdges.append(Edge(U,V,W))
        cost[(U,V)] = W
    listEdges.sort(key = lambda edgeSort : edgeSort.w)
    return listEdges,cost
      

if __name__ == "__main__":
    while read_input():
        listEdges, cost  =  create_graph()
        unionFind = DisjoinSet(N)
        mst, tree = kruskal(N,unionFind, listEdges)
        solve(mst, tree , cost ,N)      
=======

    Queries = int(input())
    #Queries = int(stdin.readline().strip())
    for q in range(Queries):
        #u , v = [int(x) for x in stdin.readline().strip().split()]
        u,v = map(int,input().split())
        print(mst - maxEdge[u][v] + cost[(u,v)])
    
    

if __name__ == "__main__":
    while 1:
        lec = stdin.readline().strip()
        if len(lec) == 0:
            break
        #N , M = map(int,lec.split())    
        N, M = [int(x) for x in lec.split()]
        N+=1
        listEdges = list()
        cost = dict()
        for i in range(M):
            #U,V,W = map(int,input().split())
            U ,V ,W = [int(x) for x in stdin.readline().strip().split()]
            listEdges.append(Edge(U,V,W))
            cost[(U,V)] = W
        listEdges.sort(key = lambda edgeSort : edgeSort.w)
        unionFind = DisjoinSet(N)
        mst, tree = kruskal(N,unionFind, listEdges)
        solve()
        
>>>>>>> dd032bc74d2cb17cc114d36a401132f38b09d12d
    