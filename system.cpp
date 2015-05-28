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
    cout<<"\t\t       ********电脑存储管理系统********       "<<endl;
    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\t*初始化设定*******5.清除记录*******6.退出*****"<<endl;
    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\t**1.存入    *************2.取出    ***********"<<endl;
    cout<<"\t\t**3.添加品牌*************4.浏览仓库***********"<<endl;
    cout<<"\t\t**********************************************"<<endl;
}

void Map::print_ini(){
    cout<<"\n\t请先初始化系统\n\t（提示：输入品牌名和品牌编号,输入-1结束初始化。\n\t如”1 海尔 2 戴尔 -1“）"<<endl;
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
        cout<<"\n\t请选择功能\n"<<endl;
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
    cout<<"请输入品牌编号和存入数量\n"<<endl;
    cin>>temp_number>>temp_amount;
    if(change(temp_number,temp_amount)){
        cout<<"存入成功"<<endl;
    }
    else{
        cout<<"存入失败"<<endl;
    }
    system("pause");
}

void Map::print_getOut(){
    cout<<"请输入品牌编号和取出数量\n"<<endl;
    cin>>temp_number>>temp_amount;
    temp_amount=-temp_amount;
    if(change(temp_number,temp_amount)){
        cout<<"取出成功"<<endl;
    }
    else{
        cout<<"取出失败,请检查"<<endl;
    }
    system("pause");
}

void Map::print_addBrand(){
    cout<<"请输入品牌编号和品牌名\n"<<endl;
    cin>>temp_number>>temp_brand_name;
    if(add(temp_number,temp_brand_name)){
        cout<<"添加成功"<<endl;
    }
    else{
        cout<<"添加失败，请检查"<<endl;
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
        cout<<"仓库为空，请存入\n"<<endl;
    }
    system("pause");
}

void Map::print_clear(){
    for(int i=0;i<tag;i++){
        delete computer[i];
    }
    tag=0;
    cout<<"清理成功"<<endl;
    system("pause");
}

bool Map::check(){
    for(int i=0;i<tag-1;i++){
        for(int j=i+1;j<tag;j++){
            if(computer[i]->number==computer[j]->number){
                cout<<"错误，请检查编号，并重新输入\n"<<endl;
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
            //。。TAT。。从stackoverflow上知道了c_str()用于将string对象转化为char*对象，解决了问题
        fprintf(fp,"%d %s %d\n",computer[i]->number,computer[i]->brand_name.c_str(),computer[i]->amount);
    }
    fclose(fp);
}


