#include "system.h"

Data::Data(int number,string brand_name):number(number),brand_name(brand_name),amount(0)
{
}

Map::Map():tag(0),temp_amount(0),temp_number(0)
{
    print_mainMap();
    print_ini();
}

void Map::print_mainMap(){
    cout<<""<<endl;
    cout<<"\t\t       ********���Դ洢����ϵͳ********       "<<endl;
    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\t*��ʼ���趨*******5.�����¼*******6.�˳�*****"<<endl;
    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\t**1.����    *************2.ȡ��    ***********"<<endl;
    cout<<"\t\t**3.���Ʒ��*************4.����ֿ�***********"<<endl;
    cout<<"\t\t**********************************************"<<endl;
}

void Map::print_ini(){
    cout<<"\n\t���ȳ�ʼ��ϵͳ\n\t����ʾ������Ʒ������Ʒ�Ʊ��,����-1������ʼ����\n\t�硱1 ���� 2 ���� -1����"<<endl;
    system("pause");
    //Sleep(1000);
    while(1){
        cin>>temp_number;
        if(temp_number==-1){
            break;
        }
        cin>>temp_brand_name;
        computer[tag++] = new Data(temp_number,temp_brand_name);
        if(!check()){
            tag=0;
            system("pause");
        }
    }
    while(1){
        system("cls");
        print_mainMap();
        cout<<"\n\t��ѡ����\n"<<endl;
        int i;
        cin>>i;
        switch(i){
            case 1:print_deposit();break;
            case 2:print_getOut();break;
            case 3:print_addBrand();break;
            case 4:print_skim();break;
            case 5:print_clear();break;
            default:break;
        }
        if(i==6){
            break;
        }
    }
    record();
}

void Map::print_deposit(){
    cout<<"������Ʒ�Ʊ�źʹ�������\n"<<endl;
    cin>>temp_number>>temp_amount;
    if(change(temp_number,temp_amount)){
        cout<<"����ɹ�"<<endl;
    }
    else{
        cout<<"����ʧ��"<<endl;
    }
    system("pause");
}

void Map::print_getOut(){
    cout<<"������Ʒ�Ʊ�ź�ȡ������\n"<<endl;
    cin>>temp_number>>temp_amount;
    temp_amount=-temp_amount;
    if(change(temp_number,temp_amount)){
        cout<<"ȡ���ɹ�"<<endl;
    }
    else{
        cout<<"ȡ��ʧ��,����"<<endl;
    }
    system("pause");
}

void Map::print_addBrand(){
    cout<<"������Ʒ�Ʊ�ź�Ʒ����\n"<<endl;
    cin>>temp_number>>temp_brand_name;
    if(add(temp_number,temp_brand_name)){
        cout<<"��ӳɹ�"<<endl;
    }
    else{
        cout<<"���ʧ�ܣ�����"<<endl;
    }
    system("pause");
}

void Map::print_skim(){
    for(int i=0;i<tag;i++){
        cout<<computer[i]->number<<":"
        <<computer[i]->brand_name<<" "
        <<computer[i]->amount<<endl;
    }
    if(tag==0){
        cout<<"�ֿ�Ϊ�գ������\n"<<endl;
    }
    system("pause");
}

void Map::print_clear(){
    for(int i=0;i<tag;i++){
        delete computer[i];
    }
    tag=0;
    cout<<"����ɹ�"<<endl;
    system("pause");
}

bool Map::check(){
    for(int i=0;i<tag-1;i++){
        for(int j=i+1;j<tag;j++){
            if(computer[i]->number==computer[j]->number){
                cout<<"���������ţ�����������\n"<<endl;
                for(int n=0;n<tag;n++){
                    delete computer[n];
                }
                return false;
            }
        }
    }
    return true;
}

bool Map::change(int number,int amount){
    for(int i=0;i<tag;i++){
        if(computer[i]->number==number){
            computer[i]->amount+=amount;
            if(computer[i]->amount<0){
                computer[i]->amount-=amount;
                return false;
            }
            return true;
        }
    }
    return false;
}

bool Map::add(int number,string brand_name){
    computer[tag++] = new Data(temp_number,temp_brand_name);
    if(!check()){
        tag--;
        return false;
    }
    return true;
}

void Map::record(){
    FILE * fp;
    fp=fopen("computer.dat","w");
    for(int i=0;i<tag;i++){
            //����TAT������stackoverflow��֪����c_str()���ڽ�string����ת��Ϊchar*���󣬽��������
        fprintf(fp,"%d %s %d\n",computer[i]->number,computer[i]->brand_name.c_str(),computer[i]->amount);
    }
    fclose(fp);
}


