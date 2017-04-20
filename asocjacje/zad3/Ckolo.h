#ifndef ZAD3_CKOLO_H
#define ZAD3_CKOLO_H


class Ckolo {
    int nrSeryjny;
    char typ;
    Ckolo();
public:
    Ckolo(int nr, char t);
    ~Ckolo();

    void Info();

    friend class Csamochod;
};


#endif //ZAD3_CKOLO_H
