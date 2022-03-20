
#ifndef COMPLEX

#define COMPLEX

//typedef double T;

template <typename T>
class Complex{
    public:

        Complex<T>();
        Complex<T>(T re, T im);

        T Re();
        T Im();

        void putRe(T);
        void putIm(T);

        Complex get_conjugate();
        void to_conjugate();

        T module();

        void operator+=(Complex);
        void operator-=(Complex);
        void operator*=(Complex);
        void operator/=(Complex);

        void operator+=(T);
        void operator-=(T);
        void operator*=(T);
        void operator/=(T);

        Complex<T> operator+(Complex);
        Complex<T> operator*(Complex);
        Complex<T> operator-(Complex);
        Complex<T> operator/(Complex);

        Complex<T> operator+(T);
        Complex<T> operator*(T);
        Complex<T> operator-(T);
        Complex<T> operator/(T);
        
        bool operator==(Complex<T>);

        Complex<T> operator!(){ return this->get_conjugate(); }

    private:
        T im; T re;

};

template <typename T>
T Re(Complex<T> a){
    return a.Re();
}

template <typename T>
T Im(Complex<T> a){
    return a.Im();
}

template <typename T>
Complex<T>::Complex(){
    this->re = 0;
    this->im = 0;
}

template <typename T>
Complex<T>::Complex(T re, T im){
    this->re = re;
    this->im = im;
}

template <typename T>
T Complex<T>::Re() {return re;}

template <typename T>
T Complex<T>::Im() {return im;}

template <typename T>
void Complex<T>::putRe(T nre) {this->re = nre;}

template <typename T>
void Complex<T>::putIm(T nim) {this->im = nim;}


template <typename T>
void Complex<T>::to_conjugate(){
    this->im = this->im * (-1);
}

template <typename T>
Complex<T> Complex<T>::get_conjugate(){
    Complex<T> nw = this;
    nw.to_conjugate();
    return nw;
}


template <typename T>
T Complex<T>::module(){
    T sq = this->re * this->re + this->im * this->im;
    return (T) sqrt(sq);
}


template <typename T>
void Complex<T>::operator+=(Complex a){
    this->im += a.im;
    this->re += a.re;
}

template <typename T>
void Complex<T>::operator-=(Complex a){
    this->im -= a.im;
    this->re -= a.re;
}

template <typename T>
void Complex<T>::operator*=(Complex a){
    this->im = this->re * a.im - this->im * a.re;
    this->re = this->re * a.re - this->im * a.im;
}

template <typename T>
void Complex<T>::operator/=(Complex a){
    Complex rev = a.get_conjugate();

    this *= rev;
    this /= (a*rev).Re();
}


template <typename T>
void Complex<T>::operator+=(T a){
    this->re += a;
}

template <typename T>
void Complex<T>::operator-=(T a){
    this->re -= a;
}

template <typename T>
void Complex<T>::operator*=(T a){
    this->re *= a;
    this->im *= a;
}

template <typename T>
void Complex<T>::operator/=(T a){
    this->re /= a;
    this->im /= a;
}


template <typename T>
Complex<T> Complex<T>::operator+(Complex a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw += a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator-(Complex a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw -= a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator*(Complex a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw *= a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator/(Complex a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw /= a;
    return nw;
}


template <typename T>
Complex<T> Complex<T>::operator+(T a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw += a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator-(T a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw -= a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator*(T a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw *= a;
    return nw;
}

template <typename T>
Complex<T> Complex<T>::operator/(T a){
    Complex nw = new Complex<T>(this->re, this->im);
    nw /= a;
    return nw;
}


template <typename T>
bool Complex<T>::operator==(Complex<T> a){
    return (this->re == a.re) && (this->im == a.im);
}

#endif