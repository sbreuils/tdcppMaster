#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <Eigen/Dense>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "chrono.hpp"


int miniRecursive(std::vector<int> vecteur, int* minimum, unsigned int indice=0)
{
    if(indice==vecteur.size()){
        return *minimum;
    }
    if(vecteur[indice] < *minimum){
        *minimum = vecteur[indice];
    }
    return miniRecursive(vecteur,minimum,indice+1) + 3;
}

int donnerNombreOccurrences(std::vector<int> vecteur, int x, unsigned int indice=0){
    if(indice>=vecteur.size()){
        return 0;
    }
    if(vecteur[indice]==x){
        return 1+donnerNombreOccurrences(vecteur,x,indice+1);
    }
    return donnerNombreOccurrences(vecteur,x,indice+1);
}

/// EXO2
std::vector<int> positionsDeX(std::vector<int> vec, std::vector<int>* indices, int x, unsigned int indice=0){
    if(indice >= vec.size()){
        return *indices;
    }
    
    std::vector<int> vecIndices =  positionsDeX(vec,indices,x,indice+1);
    if(vec[indice]==x){
        vecIndices.push_back(indice);
    }
    return vecIndices;
}

std::vector<int> unique(std::vector<int> vec){
    std::sort(vec.begin(),vec.end());

    std::vector<int> vecUnique;
    for(unsigned int i = 0 ; i <vec.size(); ++i){
        if(vecUnique.size()==0 || vec[i]!=vecUnique[vecUnique.size()-1]){
            vecUnique.push_back(vec[i]);
        }
    }

    return vecUnique;
}


typedef std::vector<std::vector<int>> Tab2D;
typedef std::vector<int> Tab1D;

Tab2D sommeTableau2D(const Tab2D& m1,const Tab2D& m2){
    Tab2D mres(m1.size(),Tab1D(m1[0].size(),0));
    
    for(unsigned int i = 0 ; i< m1.size() ; ++i){
        for(unsigned int j=0 ; j<m1[i].size() ; ++j){
            mres[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return mres;
}

void suppressionLigne(Tab2D& m1, int indiceLigne){
    m1.erase(m1.begin()+indiceLigne);
}
void suppressionColonne(Tab2D& m1, int indiceColonne){
    for(unsigned int i = 0 ; i<m1.size();++i){
        m1[i].erase(m1[i].begin()+indiceColonne);
    }
}

void insertionLigne(Tab2D& m1, int indiceLigne,const Tab1D& ligneAAjouter){
    m1.insert(m1.begin()+indiceLigne,ligneAAjouter);
}


Tab1D flatten(const Tab2D& m1){
    Tab1D res;

    for(unsigned int i = 0 ; i < m1.size() ; ++i){
        res.insert(res.end(),m1[i].begin(),m1[i].end());
    }
    return res;
}

using namespace Eigen;
typedef std::array<std::array<int,30>,30> Img3030;


double meanRef(std::vector<int>& vecLourd){
    double moyenne = 0.;
    for(unsigned int i = 0 ; i< vecLourd.size() ; ++i){
        moyenne += vecLourd[i];
    }

    return moyenne/vecLourd.size();
}

double meanCopy(std::vector<int> vecLourd){
    double moyenne = 0.;
    for(unsigned int i = 0 ; i< vecLourd.size() ; ++i){
        moyenne += vecLourd[i];
    }
    return moyenne/vecLourd.size();
}

// to delete
void afficheVector(const std::vector<int>& ve){
    std::vector<int>::const_iterator it = ve.begin();
    for(;it!= ve.end();++it){
        std::cout << *it <<" "; 
    }
    std::cout << std::endl;
} 

void afficheVectorAuto(const std::vector<int>& ve){
    std::vector<int>::const_iterator it = ve.begin();
    for(const int& e : ve){
        std::cout << e <<" "; 
    }
    std::cout << std::endl;
} 


int main(){
    // TD5 exo2
    unsigned int N = 10;
    std::vector<int> vec(N,1);
    // // vec.reserve(100);
    for(unsigned int i = 0 ; i< N ; ++i){
        vec.at(i) = i;
        std::cout << "iteration i= "<<i<<", size = "<<vec.size() << std::endl;
        std::cout << "iteration i= "<<i<<", capacity = "<<vec.capacity() << std::endl;
    }


    // vec.shrink_to_fit();
    // std::cout << "capacity = "<<vec.capacity() << std::endl;
    // std::cout << "size = "<<vec.size() << std::endl;


    // TD5 exo1 
    // std::vector<int> vec(100000000,1);
    // TD_M1::Chrono timer;

    // timer.start();
    // double moyenneAvecReference = meanRef(vec);
    // timer.stop();
    // double tempsCalculAvecReference = timer.timeSpan();

    // timer.start();
    // double moyenneAvecCopie = meanCopy(vec);
    // timer.stop();
    // double tempsCalculAvecCopie = timer.timeSpan();


    // std::cout << "temps avec copie ="<< tempsCalculAvecCopie << std::endl;
    // std::cout << "temps avec reference ="<< tempsCalculAvecReference << std::endl;

    // std::cout << "moyenne obtenue copie"<< moyenneAvecCopie << std::endl;
    // std::cout << "moyenne obtenue reference"<< moyenneAvecReference << std::endl;


    // EXO 7
    // srand(time(NULL));
    // const unsigned int N =30;
    // std::array<std::array<int,N>,N> tab2D;
    // for(unsigned int i = 0 ; i < N ; ++i){
    //     for(unsigned int j=0 ; j< N ;++j){
    //         tab2D[i][j] = 0;
    //     }
    // }


    // // structure de données du motif
    // std::vector<std::pair<int,int>> vecteurPositions; 
    // std::vector<int> vecteurNiveauxGris;
    // unsigned int Nmotif = 10;
    // for(unsigned int i =0 ; i<Nmotif ; ++i){
    //     vecteurPositions.push_back(std::make_pair(rand()%30,rand()%30));
    //     vecteurNiveauxGris.push_back(rand()%256);
    // }

    // // translation de vecteur t = [tx,ty]^\top
    // int tx = 1;
    // int ty = 1;
    // for(unsigned int i =0 ; i<Nmotif ; ++i){
    //     vecteurPositions[i].first = (vecteurPositions[i].first + ty)%30;
    //     vecteurPositions[i].second = (vecteurPositions[i].second + tx)%30;
    // } // O(Nmotif)
    // // complexité de la translation sur une image pleine (dense matrix) est en O(NxN)
    // // ici, N=30

    // for(unsigned int i =0 ; i<Nmotif ; ++i){
    //     tab2D[vecteurPositions[i].first][vecteurPositions[i].second] = vecteurNiveauxGris[i];
    // }

    // // affichage
    // for(std::array<int,30> ligne : tab2D){
    //     for(int nvGris : ligne){
    //         std::cout << nvGris << " ";
    //     }
    //     std::cout << "\n";
    // }

    // EXO 6
    // MatrixXd mat1(3,3);
    // mat1 << 3,4,1,
    //        2,0,9,
    //        6,7,8;
    // MatrixXd mat2(3,3);
    // mat2 << 6,5,8,
    //        7,9,0,
    //        3,2,1;
    // std::cout << mat1 << std::endl;

    // MatrixXd matProduitMatricielle(3,3);
    // matProduitMatricielle = mat1*mat2;
    // std::cout << matProduitMatricielle <<std::endl;


    // VectorXd vec1(3); 
    // vec1 << 1,2,3;
    // VectorXd vec2(3);
    // vec2 << -2,1,0;

    // double resultatProduitScalaire = vec1.dot(vec2); 
    // std::cout << "produit scalaire ="<< resultatProduitScalaire <<std::endl;





    // EXO 5
    // Tab2D m1 = {{2,3,4},{1,6,9}};
    // Tab2D m2 = {{0,-1,-2},{2,-3,-6}};
    // // suppressionLigne(m1, 1);
    // // suppressionColonne(m1,1);
    // Tab1D ligneAAjouter = {8,1,7};
    // insertionLigne(m1, 1,ligneAAjouter);
    
    // Tab1D m1Flat = flatten(m1);

    // // Tab2D m3 = sommeTableau2D(m1,m2);

    // for(Tab1D ligne : m1){
    //     for(int val : ligne){
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for(int val : m1Flat){
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;
    


    // std::string phraseAAnalyser("Select your version and run the represents command. Stable represents the most currently tested and supported version");
    // std::map<std::string,int> dicoOcc;

    // std::stringstream fluxChaine(phraseAAnalyser);
    // for(std::string mot ; std::getline(fluxChaine,mot,' ');){
    //     if(dicoOcc.find(mot)==dicoOcc.end()){
    //         dicoOcc[mot] = 1;
    //     }else{
    //         dicoOcc[mot] += 1;// +=1 <=> dicoOcc[mot] = dicoOcc[mot]+1
    //     }
    // }


    // for(std::pair<std::string,int> cleValeur : dicoOcc){
    //     std::cout << "cle="<<cleValeur.first << "; valeur="<<cleValeur.second << std::endl;
    // }




    // std::vector<int> vecEntiers = {2,2,4,6,8,4,8};

    // std::vector<int> elementsUniques = unique(vecEntiers);

    // std::vector<int> indicesPourFonction;
    // std::vector<int> vecIndices = positionsDeX(vecEntiers,&indicesPourFonction,4);

    // for(int val : elementsUniques){
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    // int sommeVec = sommeRecursive(vecEntiers);

    // int min = INT32_MAX;
    // int miniVec = miniRecursive(vecEntiers, &min);


    // int nbOcc = donnerNombreOccurrences(vecEntiers,1);


    // std::cout << "somme="<<sommeVec<<std::endl;
    // std::cout << "min="<<miniVec<<std::endl;
    // std::cout << "nombre occurrences de 1="<<nbOcc<<std::endl;

    return 0;
}
