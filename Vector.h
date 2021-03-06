//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_VECTOR_H
#define MATRIXALGORITHMS_VECTOR_H
template<typename T>
class Vector;

#include <vector>
#include "Matrix.h"

template<typename T>
class Vector {
private:
    std::vector<T> v;
public:
    Vector(int n=0){
        v.resize(n,0);
    }
    Vector(Vector<T> const & V){
        v=V.v;
    }

    void setN(int n){
        v.resize(n,0);
    }
    int getN() const{
        return v.size();
    }

    T& operator()(int i){
        return v[i];
    }
    T operator()(int i) const{
        if(i>=0 && i<v.size()) return v[i];
        return 0;
    }

    Vector<T> operator/(T sclar) const{
        Vector<T> ans(*this);
        for(int i=0; i<ans.getN(); ++i){
            ans(i)/=sclar;
        }
        return ans;
    }
    Vector<T> operator*(T sclar) const{
        Vector<T> ans(*this);
        for(int i=0; i<ans.getN(); ++i){
            ans(i)*=sclar;
        }
        return ans;
    }
    Vector<T> operator*(Matrix<T> const & A) const {
        if (A.getM() != v.size()) return Vector<T>();
        Vector<T> V(A.getN());
        for (int j = 0; j < A.getN(); ++j)
            for (int i = 0; i < A.getM(); ++i)
                V(j) += A(i, j) * v[i];
        return V;
    }
    T operator*(Vector<T> const & V) const {
        T ans=0;
        int n=this->getN()>V.getN()?V.getN():this->getN();
        for(int i=0; i<n; ++i){
            ans+=v[i]*V(i);
        }
        return ans;
    }
    Vector<T> const & operator-=(Vector<T> const & V){
        if(V.getN()>getN()) setN(V.getN());
        for(int i=0; i<V.getN(); ++i)
            v[i]-=V(i);
        return *this;
    }

    template <typename T0>
    friend Vector<T0> operator*(Matrix<T0> const & A, Vector<T0> const & V){
        if(A.getN()!=V.getN()) return Vector<T0>();
        Vector<T0> V1(A.getM());
        for(int j=0; j<A.getN(); ++j)
            for(int i=0; i<A.getM(); ++i)
                V1(i)+=A(i,j)*V(j);
        return V1;
    }

    template <typename T0>
    friend std::ostream& operator<<(std::ostream& out, Vector<T0>const &V) {
        out<<"(";
        for(auto&e:V.v){
            out<<e<<" ";
        }
        out<<")";
        return out;
    }

    Vector<T> const & operator=(Vector<T> const & V){
        v=V.v;
        return V;
    }
};

/*template <typename T>
T product(Vector<T> const & v1, Vector<T> const & v2){
    T ans=0;
    int n=v1.getN()>v2.getN()?v2.getN():v1.getN();
    for(int i=0; i<n; ++i){
        ans+=v1(i)*v2(i);
    }
    return ans;
}*/

template <typename T>
Vector<T> project(Vector<T> const & e, Vector<T> const & a){
    return e*((e*a)/(e*e));
}

template <typename T>
T norm(Vector<T> const & v){
    T ans = 0;
    for(int i=0; i<v.getN(); ++i)
        ans+=v(i)*v(i);
    ans=sqrt(ans);
    return ans;
}

#endif //MATRIXALGORITHMS_VECTOR_H
