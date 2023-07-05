//注:该文档中所有的"协同"字样都是笔误,应为"次要",该文档中所有的"协"字样都是笔误,应为"次"

#include "widget.h"
#include "qbuttongroup.h"
#include "ui_widget.h"

#define MAJORPLACEBUTTONMAX 9
#define SENUMBER 8 //按钮编号:塞
#define IJNUMBER 7 //按钮编号:颤或闪
#define BMCANUMBER 6 //按钮编号:边擦
#define CANUMBER 5 //按钮编号:擦
#define BMJBNUMBER 4 //按钮编号:边近
#define JBNUMBER 3 //按钮编号:近
#define BMXPNUMBER 2 //按钮编号:边协
#define XPTSNUMBER 1 //按钮编号:协同
#define IHTSNUMBER 0 //按钮编号:畅通

#define UEJMCATEGORYMAX 63
#define IYUENUMBER 54 //按钮编号:唇舌
#define IIUENUMBER 45 //按钮编号:齿舌
#define IIYBNUMBER 36 //按钮编号:齿龈
#define YBEENUMBER 27 //按钮编号:龈颚
#define XXFUNUMBER 18 //按钮编号:下阜
#define YBHZNUMBER 9 //按钮编号:龈后
#define JRUENUMBER 0 //按钮编号:卷舌

#define VOWELHEIGHTMAX 6
#define CIGCNUMBER 5 //按钮编号:次高
#define BJGCNUMBER 4 //按钮编号:半高
#define VSNUMBER 3 //按钮编号:中
#define CIDINUMBER 2 //按钮编号:半低
#define BJDINUMBER 1 //按钮编号:次低
#define DINUMBER 0 //按钮编号:低

#define VOWELWIDTHMAX 18
#define QMNUMBER 12 //按钮编号:前
#define YHNUMBER 6 //按钮编号:央
#define HZNUMBER 0 //按钮编号:后

#define UGMFARGUMENTMAX 4
#define UGMFBINUMBER 3 //按钮编号:声门闭
#define UGMFKDNUMBER 2 //按钮编号:声门开
#define UGMFHUNUMBER 1 //按钮编号:声门呼
#define UGMFXINUMBER 0 //按钮编号:声门吸

#define UGDDARGUMENTMAX 2
#define UGDDDSNUMBER 1  //按钮编号:声带动
#define UGDDJKNUMBER 0 //按钮编号:声带静

#define ULIIARGUMENTMAX 2
#define ULIISINUMBER 1 //按钮编号:双齿咝
#define ULIIWUSINUMBER 0 //按钮编号:双齿无咝

#define YRIYARGUMENTMAX 3
#define YRIYVJNUMBER 2 //按钮编号:圆唇展
#define YRIYVSNUMBER 1 //按钮编号:圆唇中
#define YRIYYRNUMBER 0 //按钮编号:圆唇圆

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->p_resultToOutput = new QString;//在widget.h中定义的输出指针:QString* p_resultToOutput;现在初始化它
    this->p_resultToOutput->clear();//清除当前的resultToOutput内存
    //创建按钮组的组
    //创建双唇组按钮数据
    this->uliy = new QButtonGroup(this);
    uliy->addButton(ui->uliyse,SENUMBER);
    uliy->addButton(ui->uliyij,IJNUMBER);
    uliy->addButton(ui->uliyca,CANUMBER);
    uliy->addButton(ui->uliyjb,JBNUMBER);
    uliy->addButton(ui->uliyxpts,XPTSNUMBER);
    uliy->addButton(ui->uliyihts,IHTSNUMBER);
    connect(this->uliy,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建唇齿组按钮数据
    this->iyii = new QButtonGroup(this);
    iyii->addButton(ui->iyiise,SENUMBER);
    iyii->addButton(ui->iyiiuj,IJNUMBER);
    iyii->addButton(ui->iyiica,CANUMBER);
    iyii->addButton(ui->iyiijb,JBNUMBER);
    iyii->addButton(ui->iyiixpts,XPTSNUMBER);
    iyii->addButton(ui->iyiiihts,IHTSNUMBER);
    connect(this->iyii,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建舌尖组按钮数据
    this->uejm = new QButtonGroup(this);
    uejm->addButton(ui->iyuese,SENUMBER+IYUENUMBER);
    uejm->addButton(ui->iyueij,IJNUMBER+IYUENUMBER);
    uejm->addButton(ui->iyuebmca,BMCANUMBER+IYUENUMBER);
    uejm->addButton(ui->iyueca,CANUMBER+IYUENUMBER);
    uejm->addButton(ui->iyuebmjb,BMJBNUMBER+IYUENUMBER);
    uejm->addButton(ui->iyuejb,JBNUMBER+IYUENUMBER);
    uejm->addButton(ui->iyuebmxp,BMXPNUMBER+IYUENUMBER);
    uejm->addButton(ui->iyuexpts,XPTSNUMBER+IYUENUMBER);
    uejm->addButton(ui->iyueihts,IHTSNUMBER+IYUENUMBER);
    uejm->addButton(ui->iiuese,SENUMBER+IIUENUMBER);
    uejm->addButton(ui->iiueuj,IJNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiuebmca,BMCANUMBER+IIUENUMBER);
    uejm->addButton(ui->iiueca,CANUMBER+IIUENUMBER);
    uejm->addButton(ui->iiuebmjb,BMJBNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiuejb,JBNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiuebmxp,BMXPNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiuexpts,XPTSNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiueihts,IHTSNUMBER+IIUENUMBER);
    uejm->addButton(ui->iiybse,SENUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybij,IJNUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybbmca,BMCANUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybca,CANUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybbmjb,BMJBNUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybjb,JBNUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybbmxp,BMXPNUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybxpts,XPTSNUMBER+IIYBNUMBER);
    uejm->addButton(ui->iiybihts,IHTSNUMBER+IIYBNUMBER);
    uejm->addButton(ui->ybeese,SENUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeeuj,IJNUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeebmca,BMCANUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeeca,CANUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeebmjb,BMJBNUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeejb,JBNUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeebmxp,BMXPNUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeexpts,XPTSNUMBER+YBEENUMBER);
    uejm->addButton(ui->ybeeihts,IHTSNUMBER+YBEENUMBER);
    uejm->addButton(ui->xxfuxpts,XPTSNUMBER+XXFUNUMBER);
    uejm->addButton(ui->xxfuihts,IHTSNUMBER+XXFUNUMBER);
    uejm->addButton(ui->ybhzse,SENUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzuj,IJNUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzbmca,BMCANUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzca,CANUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzbmjb,BMJBNUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzjb,JBNUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzbmxp,BMXPNUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzxpts,XPTSNUMBER+YBHZNUMBER);
    uejm->addButton(ui->ybhzihts,IHTSNUMBER+YBHZNUMBER);
    uejm->addButton(ui->jruese,SENUMBER+JRUENUMBER);
    uejm->addButton(ui->jrueuj,IJNUMBER+JRUENUMBER);
    uejm->addButton(ui->jruebmca,BMCANUMBER+JRUENUMBER);
    uejm->addButton(ui->jrueca,CANUMBER+JRUENUMBER);
    uejm->addButton(ui->jruebmjb,BMJBNUMBER+JRUENUMBER);
    uejm->addButton(ui->jruejb,JBNUMBER+JRUENUMBER);
    uejm->addButton(ui->jruebmxp,BMXPNUMBER+JRUENUMBER);
    uejm->addButton(ui->jruexpts,XPTSNUMBER+JRUENUMBER);
    uejm->addButton(ui->jrueihts,IHTSNUMBER+JRUENUMBER);
    connect(this->uejm,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建硬腭组数据
    this->ykee = new QButtonGroup(this);
    ykee->addButton(ui->ykeese,SENUMBER);
    ykee->addButton(ui->ykeebmca,BMCANUMBER);
    ykee->addButton(ui->ykeeca,CANUMBER);
    ykee->addButton(ui->ykeebmjb,BMJBNUMBER);
    ykee->addButton(ui->ykeejb,JBNUMBER);
    ykee->addButton(ui->ykeebmxp,BMXPNUMBER);
    ykee->addButton(ui->ykeexpts,XPTSNUMBER);
    ykee->addButton(ui->ykeeihts,IHTSNUMBER);
    connect(this->ykee,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建腭央组数据
    this->eeyh = new QButtonGroup(this);
    eeyh->addButton(ui->eeyhse,SENUMBER);
    eeyh->addButton(ui->eeyhbmca,BMCANUMBER);
    eeyh->addButton(ui->eeyhca,CANUMBER);
    eeyh->addButton(ui->eeyhbmjb,BMJBNUMBER);
    eeyh->addButton(ui->eeyhjb,JBNUMBER);
    eeyh->addButton(ui->eeyhbmxp,BMXPNUMBER);
    eeyh->addButton(ui->eeyhxpts,XPTSNUMBER);
    eeyh->addButton(ui->eeyhihts,IHTSNUMBER);
    connect(this->eeyh,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建软腭组数据
    this->rree = new QButtonGroup(this);
    rree->addButton(ui->rreese,SENUMBER);
    rree->addButton(ui->rreebmca,BMCANUMBER);
    rree->addButton(ui->rreeca,CANUMBER);
    rree->addButton(ui->rreebmjb,BMJBNUMBER);
    rree->addButton(ui->rreejb,JBNUMBER);
    rree->addButton(ui->rreebmxp,BMXPNUMBER);
    rree->addButton(ui->rreexpts,XPTSNUMBER);
    rree->addButton(ui->rreeihts,IHTSNUMBER);
    connect(this->rree,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建小舌组数据
    this->xnue = new QButtonGroup(this);
    xnue->addButton(ui->xnuese,SENUMBER);
    xnue->addButton(ui->xnueij,IJNUMBER);
    xnue->addButton(ui->xnuebmca,BMCANUMBER);
    xnue->addButton(ui->xnueca,CANUMBER);
    xnue->addButton(ui->xnuebmjb,BMJBNUMBER);
    xnue->addButton(ui->xnuejb,JBNUMBER);
    xnue->addButton(ui->xnuebmxp,BMXPNUMBER);
    xnue->addButton(ui->xnuexpts,XPTSNUMBER);
    xnue->addButton(ui->xnueihts,IHTSNUMBER);
    connect(this->xnue,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建舌根组数据
    this->uegf = new QButtonGroup(this);
    uegf->addButton(ui->uegfse,SENUMBER);
    uegf->addButton(ui->uegfuj,IJNUMBER);
    uegf->addButton(ui->uegfbmca,BMCANUMBER);
    uegf->addButton(ui->uegfca,CANUMBER);
    uegf->addButton(ui->uegfbmjb,BMJBNUMBER);
    uegf->addButton(ui->uegfjb,JBNUMBER);
    uegf->addButton(ui->uegfbmxp,BMXPNUMBER);
    uegf->addButton(ui->uegfxpts,XPTSNUMBER);
    connect(this->uegf,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    mapOfUnroundedVowels = new QMap<int,QString>;
    mapOfUnroundedVowels->clear();
    mapOfRoundedVowels = new QMap<int,QString>;
    mapOfRoundedVowels->clear();
    uegf->addButton(ui->cigcqm,MAJORPLACEBUTTONMAX+CIGCNUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+QMNUMBER,"ɪ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+QMNUMBER,"ʏ");
    uegf->addButton(ui->cigcyh,MAJORPLACEBUTTONMAX+CIGCNUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+YHNUMBER,"ᵻ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+YHNUMBER,"ᵿ");
    uegf->addButton(ui->cigchz,MAJORPLACEBUTTONMAX+CIGCNUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+HZNUMBER,"ω");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIGCNUMBER+HZNUMBER,"ʊ");
    uegf->addButton(ui->bjgcqm,MAJORPLACEBUTTONMAX+BJGCNUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+QMNUMBER,"e");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+QMNUMBER,"ø");
    uegf->addButton(ui->bjgcyh,MAJORPLACEBUTTONMAX+BJGCNUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+YHNUMBER,"ɘ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+YHNUMBER,"ɵ");
    uegf->addButton(ui->bjgchz,MAJORPLACEBUTTONMAX+BJGCNUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+HZNUMBER,"ɤ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJGCNUMBER+HZNUMBER,"o");
    uegf->addButton(ui->vsqm,MAJORPLACEBUTTONMAX+VSNUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+QMNUMBER,"ᴇ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+QMNUMBER,"ø̞");
    uegf->addButton(ui->vsyh,MAJORPLACEBUTTONMAX+VSNUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+YHNUMBER,"ə");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+YHNUMBER,"ɵ̞");
    uegf->addButton(ui->vshz,MAJORPLACEBUTTONMAX+VSNUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+HZNUMBER,"ɤ̞");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+VSNUMBER+HZNUMBER,"ⱺ");
    uegf->addButton(ui->bjdiqm,MAJORPLACEBUTTONMAX+BJDINUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+QMNUMBER,"ɛ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+QMNUMBER,"œ");
    uegf->addButton(ui->bjdiyh,MAJORPLACEBUTTONMAX+BJDINUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+YHNUMBER,"ɜ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+YHNUMBER,"ɞ");
    uegf->addButton(ui->bjdihz,MAJORPLACEBUTTONMAX+BJDINUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+HZNUMBER,"ʌ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+BJDINUMBER+HZNUMBER,"ɔ");
    uegf->addButton(ui->cidiqm,MAJORPLACEBUTTONMAX+CIDINUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+QMNUMBER,"æ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+QMNUMBER,"œ̞");
    uegf->addButton(ui->cidiyh,MAJORPLACEBUTTONMAX+CIDINUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+YHNUMBER,"ɐ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+YHNUMBER,"ɞ̞");
    uegf->addButton(ui->cidihz,MAJORPLACEBUTTONMAX+CIDINUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+HZNUMBER,"ʌ̞");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+CIDINUMBER+HZNUMBER,"ɔ̞");
    uegf->addButton(ui->diqm,MAJORPLACEBUTTONMAX+DINUMBER+QMNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+QMNUMBER,"a");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+QMNUMBER,"ɶ");
    uegf->addButton(ui->diyh,MAJORPLACEBUTTONMAX+DINUMBER+YHNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+YHNUMBER,"ᴀ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+YHNUMBER,"ɒ̈");
    uegf->addButton(ui->dihz,MAJORPLACEBUTTONMAX+DINUMBER+HZNUMBER);
    mapOfUnroundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+HZNUMBER,"ɑ");
    mapOfRoundedVowels->insert(MAJORPLACEBUTTONMAX+DINUMBER+HZNUMBER,"ɒ");
    connect(this->uegf,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建声门组数据
    this->ugmf = new QButtonGroup(this);
    ugmf->addButton(ui->ugmfbi,UGMFBINUMBER);
    ugmf->addButton(ui->ugmfkd,UGMFKDNUMBER);
    ugmf->addButton(ui->ugmfhu,UGMFHUNUMBER);
    ugmf->addButton(ui->ugmfxi,UGMFXINUMBER);
    connect(this->ugmf,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建声带组数据
    this->ugdd = new QButtonGroup(this);
    ugdd->addButton(ui->ugddds,UGDDDSNUMBER);
    ugdd->addButton(ui->ugddjk,UGDDJKNUMBER);
    connect(this->ugdd,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建双齿组数据
    this->ulii = new QButtonGroup(this);
    ulii->addButton(ui->uliisi,ULIISINUMBER);
    ulii->addButton(ui->uliiwusi,ULIIWUSINUMBER);
    connect(this->ulii,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建鼻组数据
    this->bi = new QButtonGroup(this);
    bi->addButton(ui->bibi,SENUMBER);
    bi->addButton(ui->biij,IJNUMBER);
    bi->addButton(ui->bica,CANUMBER);
    bi->addButton(ui->bikd,IHTSNUMBER);
    connect(this->bi,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建圆唇组数据
    this->yriy = new QButtonGroup(this);
    yriy->addButton(ui->yriyvj,YRIYVJNUMBER);
    yriy->addButton(ui->yriyvs,YRIYVSNUMBER);
    yriy->addButton(ui->yriyyr,YRIYYRNUMBER);
    connect(this->yriy,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(anyClick()));
    //创建成音节数据
    this->igybjp = ui->igybjp;
    connect(this->igybjp,SIGNAL(clicked(bool)),this,SLOT(anyClick()));
    ui->resultDisplayer->setText("稳态假想人声信号IPA生成器\n作者:哔哩哔哩uid4055425");
}

Widget::~Widget()
{
    delete ui;
}

//通过舌尖按钮组当前选中的按钮编号来取得舌尖发声部位
int uejm_getPlace(int uejmButtonGroupCheckedId)
{
    return uejmButtonGroupCheckedId-(uejmButtonGroupCheckedId%MAJORPLACEBUTTONMAX);
}

//添加阻音符号的通用办法
void zuAppend
    (
     QString* p_targetToAppend,
     int placeChecked,//调音部位
     QButtonGroup* p_ugmfButtongroup,//声门状态
     QButtonGroup* p_ugddButtongroup,//声带状态
     QButtonGroup* p_uliiButtongroup,//双齿状态
     QButtonGroup* p_biButtonGroup,//鼻状态
     QButtonGroup* p_yriyButtonGroup,//圆唇程度
     bool igybjp,//成音节
     const QString biybSymbol,//鼻音符号
     const QString voseybSymbol,//浊塞音符号
     const QString qkseybSymbol,//清塞音符号
     const QString nwbcybSymbol,//内爆音符号
     const QString ijybSymbol,//颤音符号
     const QString vobmcaybSymbol,//浊边擦音符号
     const QString vocaybSymbol,//浊擦音符号
     const QString vosiybSymbol,//浊咝音符号
     const QString qkbmcaybSymbol,//清边擦音符号
     const QString qkcaybSymbol,//清擦音符号
     const QString qksiybSymbol,//清咝音符号
     const QString sevzybSymbol,//塞喌音符号
     const QString vobmcavzybSymbol,//浊边擦喌音符号
     const QString qkbmcavzybSymbol,//清边擦喌音符号
     const QString vocavzybSymbol,//浊擦喌音符号
     const QString qkcavzybSymbol,//清擦喌音符号
     const QString vosivzybSymbol,//浊咝喌音符号
     const QString qksivzybSymbol//清咝喌音符号
    )
{
    switch(placeChecked)
    {
        //首先检视当前正在读取的按钮组是否按下了塞音按钮,是的话就判定为塞音或鼻音

        case SENUMBER://如果该调音部位是塞音或鼻音
        {
            //检视是不是鼻音
            if(p_biButtonGroup->checkedId()==IHTSNUMBER)//如果是鼻音,那就输出鼻音符号
            {
                if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
                {
                    p_targetToAppend->append("͡");
                }
                switch(p_ugmfButtongroup->checkedId())
                {
                    case UGMFBINUMBER:
                    case UGMFKDNUMBER://如果声门关闭或自然打开,那么判定为常规鼻音
                    {
                        p_targetToAppend->append(biybSymbol);//添加鼻音符号
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那就添加清化符号
                        {
                            p_targetToAppend->append("̊");
                        }
                        break;
                    }
                    case UGMFHUNUMBER://如果声门呼气,那么判定为呼鼻音
                    {
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那就判定为清呼鼻音,添加清塞音符号和鼻化符号(作者定义,暂用)
                        {
                            p_targetToAppend->append(qkseybSymbol);
                            p_targetToAppend->append("̃");
                        }
                        else//否则判定为浊呼鼻音,添加浊塞音符号和鼻化符号(作者定义,暂用)
                        {
                            p_targetToAppend->append(voseybSymbol);
                            p_targetToAppend->append("̃");
                        }
                        break;
                    }
                    case UGMFXINUMBER://如果声门吸气,那么判定为吸气鼻音
                    {
                        p_targetToAppend->append(biybSymbol);//添加鼻音符号
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那就添加清化符号
                        {
                            p_targetToAppend->append("̊");
                        }
                        p_targetToAppend->append("↓");//添加吸气符号
                        break;
                    }
                    default://如果是异常输入,直接结束判断
                    {
                        break;
                    }
                }
            }
            else//如果不是鼻音,那就输出塞音符号
            {
                if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
                {
                    p_targetToAppend->append("͡");
                }

                //检视声门状态
                switch(p_ugmfButtongroup->checkedId())
                {
                    case UGMFXINUMBER://如果在吸气,那么判定为内爆音或喌音
                    {
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为塞喌音,添加喌音符号
                        {
                            p_targetToAppend->append(sevzybSymbol);
                        }
                        else//如果声带振动,那么判定为内爆音,添加内爆音符号
                        {
                            p_targetToAppend->append(nwbcybSymbol);
                        }
                        break;
                    }

                    case UGMFKDNUMBER://如果声门自然打开,那么判定为浊塞音或者驰音
                    {
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为弛音,添加浊塞音符号和清化符号
                        {
                            p_targetToAppend->append(voseybSymbol);
                            p_targetToAppend->append("̥");
                        }
                        else//如果声带振动,那么判定为浊塞音,添加浊塞音符号
                        {
                            p_targetToAppend->append(voseybSymbol);
                        }
                        break;
                    }

                    case UGMFHUNUMBER://如果声门呼气,那么判定为清塞音或者紧浊塞音
                    {
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为请塞音,添加请塞音符号
                        {
                            p_targetToAppend->append(qkseybSymbol);
                        }
                        else//如果声带振动,那么判定为紧浊塞音,添加清塞音符号和浊化符号
                        {
                            p_targetToAppend->append(qkseybSymbol);
                            p_targetToAppend->append("̬");
                        }
                        break;
                    }

                    case UGMFBINUMBER: default://如果声门关闭或是异常输入,那么暂且按常规浊塞音或清塞音处理
                    {
                        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为请塞音,添加请塞音符号
                        {
                            p_targetToAppend->append(qkseybSymbol);

                        }
                        else//如果声带振动,那么判定为浊塞音,添加浊塞音符号
                        {
                            p_targetToAppend->append(voseybSymbol);
                        }
                        break;
                    }
                }
            }
            if(p_yriyButtonGroup->checkedId()==YRIYVSNUMBER)//如果圆唇程度为"中",那么添加一个"更圆唇"符号
            {
                p_targetToAppend->append("̹");
            }
            if(igybjp)//如果成音节,那么添加一个成音节符号
            {
                p_targetToAppend->append("̩");
            }
            break;
        }

        case IJNUMBER://如果该调音部位是颤音或闪音
        {
            if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
            {
                p_targetToAppend->append("͡");
            }
            p_targetToAppend->append(ijybSymbol);//添加颤音或闪音符号
            if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么添加清化符号
            {
                p_targetToAppend->append("̊");
            }
            if(p_biButtonGroup->checkedId()==IHTSNUMBER)//如果鼻腔打开,那么添加鼻化符号
            {
                p_targetToAppend->append("̃");
            }
            if(p_uliiButtongroup->checkedId()==ULIISINUMBER)//如果有咝音,那么添加齿化符号
            {
                p_targetToAppend->append("̪");
            }
            if(p_yriyButtonGroup->checkedId()==YRIYVSNUMBER)//如果圆唇程度为"中",那么添加一个"更圆唇"符号
            {
                p_targetToAppend->append("̹");
            }
            if(igybjp)//如果成音节,那么添加一个成音节符号
            {
                p_targetToAppend->append("̩");
            }
            if(p_ugmfButtongroup->checkedId()==UGMFXINUMBER)//如果声门吸气,那么添加一个吸气符号
            {
                p_targetToAppend->append("↓");//添加吸气符号
            }
            break;
        }

        case BMCANUMBER://如果该调音部位是边擦音
        {
            if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
            {
                p_targetToAppend->append("͡");
            }

            switch(p_ugmfButtongroup->checkedId())//检视声门状态
            {
                case UGMFKDNUMBER://如果声门自然打开,判定为浊边擦音或清弛边擦音
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清弛边擦音,添加浊边擦音符号和清化符号
                    {
                        p_targetToAppend->append(vobmcaybSymbol);
                        p_targetToAppend->append("̊");
                    }
                    else//否则判定为浊边擦音,添加浊边擦音符号
                    {
                        p_targetToAppend->append(vobmcaybSymbol);
                    }
                    break;
                }

                case UGMFHUNUMBER://如果声门呼气,判定为清边擦音或浊紧边擦音
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清边擦音,添加清边擦音符号
                    {
                        p_targetToAppend->append(qkbmcaybSymbol);
                    }
                    else//否则判定为浊紧边擦音,添加清边擦音符号和浊化符号
                    {
                        p_targetToAppend->append(qkbmcaybSymbol);
                        p_targetToAppend->append("̬");
                    }
                    break;
                }

                case UGMFXINUMBER://如果声门吸气,判定为边擦喌音
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清边擦喌音,添加清边擦喌音符号
                    {
                        p_targetToAppend->append(qkbmcavzybSymbol);
                    }
                    else//否则判定为浊边擦喌音,添加浊边擦喌音符号
                    {
                        p_targetToAppend->append(vobmcavzybSymbol);
                    }
                    break;
                }

                case UGMFBINUMBER: default://如果声门关闭或是异常输入,那么暂且按常规清边擦音或浊边擦音处理
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为请边擦音,添加请边擦音符号
                    {
                        p_targetToAppend->append(qkbmcaybSymbol);
                    }
                    else//如果声带振动,那么判定为浊边擦音,添加浊边擦音符号
                    {
                        p_targetToAppend->append(vobmcaybSymbol);
                    }
                    break;
                }
            }
            if(p_biButtonGroup->checkedId()==IHTSNUMBER)//如果鼻腔打开,那么添加鼻化符号
            {
                p_targetToAppend->append("̃");
            }
            if(p_uliiButtongroup->checkedId()==ULIISINUMBER)//如果有咝音,那么添加齿化符号
            {
                p_targetToAppend->append("̪");
            }
            if(p_yriyButtonGroup->checkedId()==YRIYVSNUMBER)//如果圆唇程度为"中",那么添加一个"更圆唇"符号
            {
                p_targetToAppend->append("̹");
            }
            if(igybjp)//如果成音节,那么添加一个成音节符号
            {
                p_targetToAppend->append("̩");
            }
            break;
        }

        case CANUMBER://如果该调音部位是擦音
        {
            if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
            {
                p_targetToAppend->append("͡");
            }

            switch(p_ugmfButtongroup->checkedId())//检视声门状态
            {
                case UGMFKDNUMBER://如果声门自然打开,判定为浊擦音或清弛擦音
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清弛擦音,添加浊擦音符号和清化符号
                    {
                        p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?vosiybSymbol:vocaybSymbol);
                        p_targetToAppend->append("̊");
                    }
                    else//否则判定为浊擦音,添加浊擦音符号
                    {
                        p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?vosiybSymbol:vocaybSymbol);
                    }
                    break;
                }

                case UGMFHUNUMBER://如果声门呼气,判定为清擦音或浊紧擦音
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清擦音,添加清擦音符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?qksiybSymbol:qkcaybSymbol);
                    }
                    else//否则判定为浊紧擦音,添加清擦音符号和浊化符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?qksiybSymbol:qkcaybSymbol);
                            p_targetToAppend->append("̬");
                    }
                    break;
                }

                case UGMFXINUMBER:
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为清擦喌音,添加清边擦喌音符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?qksivzybSymbol:qkcavzybSymbol);
                    }
                    else//否则判定为浊边擦喌音,添加浊擦喌音符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?vosivzybSymbol:vocavzybSymbol);
                    }
                    break;
                }

                case UGMFBINUMBER: default://如果声门关闭或是异常输入,那么暂且按常规清擦音或浊擦音处理
                {
                    if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么判定为请擦音,添加请擦音符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?qksiybSymbol:qkcaybSymbol);
                    }
                    else//如果声带振动,那么判定为浊擦音,添加浊擦音符号
                    {
                            p_targetToAppend->append(p_uliiButtongroup->checkedId()==ULIISINUMBER?vosiybSymbol:vocaybSymbol);
                    }
                    break;
                }
            }
            if(p_biButtonGroup->checkedId()==IHTSNUMBER)//如果鼻腔打开,那么添加鼻化符号
            {
                p_targetToAppend->append("̃");
            }
            if(p_yriyButtonGroup->checkedId()==YRIYVSNUMBER)//如果圆唇程度为"中",那么添加一个"更圆唇"符号
            {
                p_targetToAppend->append("̹");
            }
            if(igybjp)//如果成音节,那么添加一个成音节符号
            {
                p_targetToAppend->append("̩");
            }
            break;
        }

        default:
        {
            break;
        }
    }
}

void xptsAppendForZu//为阻音添加协同调音标记的通用方法
    (
     QString* p_targetToAppend,
     int placeChecked,//当前调音部位的状态
     const QString xptsSymbol,//该部位的协同调音符号
     const QString bmxpSymbol//该部位的边协同调音符号
    )
{
    switch(placeChecked)
    {
        case JBNUMBER:
        case XPTSNUMBER://如果该部位的近音或者协同调音按钮按下
        {
            p_targetToAppend->append(xptsSymbol);
            break;
        }
        case BMJBNUMBER:
        case BMXPNUMBER://如果该部位的边近音或者边协同调音按钮按下
        {
            p_targetToAppend->append(bmxpSymbol);
            break;
        }
        default:
        {
            break;
        }
    }
}

void jbAppend
    (
     QString* p_targetToAppend,
     int placeChecked,//当前调音部位的状态
     const QString jbSymbol,//该部位的近音符号
     const QString igybjpjbSymbol,//该部位的成音节近音符号
     const QString bmjbSymbol,//该部位的边近音符号
     QButtonGroup* p_ugmfButtongroup,//声门状态
     QButtonGroup* p_ugddButtongroup,//声带状态
     QButtonGroup* p_uliiButtongroup,//双齿状态
     QButtonGroup* p_biButtonGroup,//鼻状态
     QButtonGroup* p_yriyButtonGroup,//圆唇程度
     bool igybjp//成音节
    )
{
    switch(placeChecked)
    {
        case JBNUMBER://如果该部位的近音按钮按下
        {
            if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
            {
                p_targetToAppend->append("͡");
            }
            if(igybjp)//如果成音节,那么添加该部位的成音节近音符号
            {
                p_targetToAppend->append(igybjpjbSymbol);
            }
            else//否则,添加该部位的近音符号
            {
                p_targetToAppend->append(jbSymbol);
            }
            break;
        }
        case BMJBNUMBER://如果该部位的边近音按钮按下
        {
            if(p_targetToAppend->isEmpty()==0)//如果前面已经有符号,那么添加连音符
            {
                p_targetToAppend->append("͡");
            }
            p_targetToAppend->append(bmjbSymbol);//添加该部位的边近音符号
            if(igybjp)//如果成音节,那么添加一个成音节符号
            {
                p_targetToAppend->append("̩");
            }
            break;
        }
        default:
        {
            break;
        }
    }
    switch(placeChecked)//添加附加符号
    {
        case JBNUMBER:
        case BMJBNUMBER:
        if(p_ugddButtongroup->checkedId()==UGDDJKNUMBER)//如果声带没在振动,那么添加清化符号
        {
            p_targetToAppend->append("̊");
        }
        if(p_biButtonGroup->checkedId()==IHTSNUMBER)//如果鼻腔打开,那么添加鼻化符号
        {
            p_targetToAppend->append("̃");
        }
        if(p_uliiButtongroup->checkedId()==ULIISINUMBER)//如果有咝音,那么添加齿化符号
        {
            p_targetToAppend->append("̪");
        }
        if(p_yriyButtonGroup->checkedId()==YRIYVSNUMBER)//如果圆唇程度为"中",那么添加一个"更圆唇"符号
        {
            p_targetToAppend->append("̹");
        }
        switch(p_ugmfButtongroup->checkedId())//检视声门状态
        {
            case UGMFHUNUMBER://如果声门呼气,那么判定为呼近音,添加向上箭头
            {
                p_targetToAppend->append("↑");
                break;
            }
            case UGMFXINUMBER://如果声门吸气,那么判定为吸气近音,添加向下箭头
            {
                p_targetToAppend->append("↓");
                break;
            }
            default://如果是其他情况,那么无需添加符号
            {
                break;
            }
        }
        default:
        {
            break;
        }
    }
}

void xptsAppendForTs//为通音添加协同调音的通用方法
    (
     QString* p_targetToAppend,
     int placeChecked,//当前调音部位的状态
     const QString xptsSymbol,//该部位的协同调音符号
     const QString bmxpSymbol//该部位的边协同调音符号
    )
{
    switch(placeChecked)
    {
        case XPTSNUMBER://如果该部位的协同调音按钮按下
        {
                p_targetToAppend->append(xptsSymbol);
                break;
        }
        case BMXPNUMBER://如果该部位的边协同调音按钮按下
        {
                p_targetToAppend->append(bmxpSymbol);
                break;
        }
        default:
        {
                break;
        }
    }
}

slots void Widget::anyClick() //当识别到"任何按钮按下"这一信号时,更新文本框中显示的内容
{
    this->p_resultToOutput->clear();//清除当前的resultToOutput内存
    //检查是否为阻音,如果是则添加对应的符号
    if(ui->ugmfbi->isChecked())//特别地,如果声门关闭,直接添加声门塞音符号
    {
        this->p_resultToOutput->append("ʔ");
            if(ui->bikd->isChecked())//如果鼻腔打开,那么添加鼻化符号
        {
            this->p_resultToOutput->append("̃");
        }
        if(ui->yriyvs->isChecked())//如果圆唇程度为"中",那么添加一个"更圆唇"符号
        {
            this->p_resultToOutput->append("̹");
        }
        if(ui->igybjp->isChecked())//如果成音节,那么添加一个成音节符号
        {
            this->p_resultToOutput->append("̩");
        }
        if(ui->uliisi->isChecked())//如果有咝音,那么添加齿化符号
        {
            this->p_resultToOutput->append("̪");
        }
    }
    zuAppend(this->p_resultToOutput,this->uegf->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ʡ̬̃","ʡ̬","ʡ","ʡ̬↓","ʡ̆","ʢˡ","ʢ","ʢ̪","ʜˡ","ʜ","ʜ̪","ʡ↓","ʢˡ↓","ʜˡ↓","ʢ↓","ʜ↓","ʢ̪↓","ʜ̪↓");//舌根阻音
    zuAppend(this->p_resultToOutput,this->xnue->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ɴ","ɢ","q","ʛ","ʀ","ʟ̝̠","ʁ","ʁ̪","\U0001DF04̠","χ","χ̪","q↓","ʟ̝̠↓","\U0001DF04̠↓","ʁ↓","χ↓","ʁ̪↓","χ̪↓");//小舌阻音
    zuAppend(this->p_resultToOutput,this->rree->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ŋ","g","k","ɠ","","ʟ̝","ɣ","ɣ̪","\U0001DF04","x","x̪","k↓","ʟ̝↓","\U0001DF04↓","ɣ↓","x↓","ɣ̪↓","x̪↓");//软腭阻音
    zuAppend(this->p_resultToOutput,this->eeyh->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ɲ̈","ɟ̈","c̈","ʄ̈","","ʎ̝̈","ʝ̈","ʝ̪̈","\U0001DF06̈","ç̈","ç̪̈","ǂ̈","ʎ̝̈↓","\U0001DF06̈↓","ʝ̈↓","ç̈↓","ʝ̪̈↓","ç̪̈↓");//腭央阻音
    zuAppend(this->p_resultToOutput,this->ykee->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ɲ","ɟ","c","ʄ","","ʎ̝","ʝ","ʝ̪","\U0001DF06̈","ç","ç̪","ǂ","ʎ̝↓","\U0001DF06↓","ʝ↓","ç↓","ʝ̪↓","ç̪↓");//硬腭阻音
    switch(uejm_getPlace(this->uejm->checkedId()))//舌尖阻音
    {
        case JRUENUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "ɳ","ɖ","ʈ","ᶑ","ɽ","\U0001DF05","ð˞","ʐ","ꞎ","θ˞","ʂ","‼","‖˞̬","‖˞","ð˞↓","θ˞↓","ʐ↓","ʂ↓");//卷舌阻音
            break;
        }
        case YBHZNUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "n̠","d̠","t̠","ɗ̠","r̠","ɮ̠","ðᶾ","z̠","ɬ̠","θᶾ","s̠","ǃ̠","‖̬̠","‖̠","ðᶾ↓","θᶾ↓","z̠↓","s̠↓");//龈后阻音
            break;
        }
        case YBEENUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "ȵ","ȡ","ȶ","ʄ̟","ɾ","ȴ̝","ʝ̟","ʑ","\U0001DF06̟↓","ç̟","ɕ","ǂ̟","ȴ̝↓","\U0001DF06̟↓","ʝ̟↓","ç̟↓","ʑ↓","ɕ↓");//龈颚阻音
            break;
        }
        case IIYBNUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "n̟","d̟","t̟","ɗ̟","r̟","ɮ̟","ð̠","z̟","ɬ̟","θ̠","s̟","ǃ̟","‖̬̟","‖̟","ð̠↓","θ̠↓","z̟↓","s̟↓");//齿龈阻音
            break;
        }
        case IIUENUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "n̪","d̪","t̪","ɗ̪","ɾ̪","ɮ̪","ð","z̪","ɬ̪","θ","s","ǃ̪","‖̬̪","‖̪","ð↓","θ↓","z̪↓","s̪↓");//齿舌阻音
            break;
        }
        case IYUENUMBER:
        {
            zuAppend(this->p_resultToOutput,this->uejm->checkedId()%MAJORPLACEBUTTONMAX,this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
                     "n̼","d̼","t̼","ɗ̼","r̼","ɮ̼","ð̼","z̼","ɬ̼","θ̼","s̼","ǃ̼","‖̬̼","‖̼","ð̼↓","θ̼↓","z̼↓","s̼↓");//唇舌阻音
            break;
        }
        default:
        {
            break;
        }
    }
    zuAppend(this->p_resultToOutput,this->iyii->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "ɱ","b̪","p̪","ɓ̪","ʙ̪","","v","v̪","","f","f̪","ʘ̪","","","v↓","f↓","v̪↓","f̪↓");//唇齿阻音
    zuAppend(this->p_resultToOutput,this->uliy->checkedId(),this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked(),
             "m","b","p","ɓ","ʙ","","β","β̪","","ɸ","ɸ̪","ʘ","","","β↓","ɸ↓","β̪↓","ɸ̪↓");//双唇阻音
    //接下来检查近音和协同调音:如果待输出区已经有字符,说明是阻音,那么都添加对应的协同调音符号
    if(p_resultToOutput->isEmpty()==0)
    {
        xptsAppendForZu(this->p_resultToOutput,uegf->checkedId(),"ˤ","ˤᶩ");//舌根
        xptsAppendForZu(this->p_resultToOutput,xnue->checkedId(),"ˀ","\U0001079C");//小舌
        xptsAppendForZu(this->p_resultToOutput,rree->checkedId(),"ˠ","ᶫ");//软腭
        xptsAppendForZu(this->p_resultToOutput,eeyh->checkedId(),"ᶡ","\U000107A1");//腭央
        xptsAppendForZu(this->p_resultToOutput,ykee->checkedId(),"ʲ","\U000107A0");//硬腭
        switch(uejm_getPlace(uejm->checkedId()))//舌尖
        {
            case JRUENUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ʵ","ᶩ");//卷舌
                break;
            }
            case YBHZNUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶾ","ᶾˡ");//龈后
                break;
            }
            case XXFUNUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶨ","");//下阜
                break;
            }
            case YBEENUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶽ","ᶽˡ");//龈颚
                break;
            }
            case IIYBNUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶻ","ᶻˡ");//齿龈
                break;
            }
            case IIUENUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶞ","ᶞˡ");//齿舌
                break;
            }
            case IYUENUMBER:
            {
                xptsAppendForZu(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶞ̼","ˡ̼");//唇舌
                break;
            }
            default:
            {
                break;
            }
        }
        xptsAppendForZu(this->p_resultToOutput,iyii->checkedId(),"ᶹ","");//唇齿
        xptsAppendForZu(this->p_resultToOutput,uliy->checkedId(),"ᵝ","");//双唇
        if(this->p_resultToOutput->isEmpty()==0&&this->yriy->checkedId()==YRIYYRNUMBER)//特别地,如果圆唇程度是"圆",添加圆唇符号
        {
            this->p_resultToOutput->append("ʷ");
        }
    }
    else//如果待输出区没有字符,说明是近音或元音
    {
        //添加近音符号
        jbAppend(this->p_resultToOutput,uegf->checkedId(),"ʕ","ʕ̩","ʕˡ",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//舌根
        jbAppend(this->p_resultToOutput,xnue->checkedId(),"ʁ̘","ʁ̘̩","ʟ̠",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//小舌
        jbAppend(this->p_resultToOutput,rree->checkedId(),"ɰ","ɯ","ʟ",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//软腭
        jbAppend(this->p_resultToOutput,eeyh->checkedId(),"ɉ","ɨ","ʎ̠",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//腭央
        jbAppend(this->p_resultToOutput,ykee->checkedId(),"j","i","ʎ",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//硬腭
        switch(uejm_getPlace(this->uejm->checkedId()))//舌尖
        {
            case JRUENUMBER://卷舌
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ɻ","ɻ̩","ɭ",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            case YBHZNUMBER://龈后
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ɹ̠","ɹ̠̩","l̠",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            case YBEENUMBER://龈颚
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"j̟","i̟","ʎ̟",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            case IIYBNUMBER://齿龈
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ɹ̟","ɹ̟̩","l̟",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            case IIUENUMBER://齿舌
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ɹ̪","ɹ̪̩","l̪",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            case IYUENUMBER://唇舌
            {
                jbAppend(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ɹ̼","ɹ̼̩","l̼",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());
                break;
            }
            default:
            {
                break;
            }
        }
        jbAppend(this->p_resultToOutput,iyii->checkedId(),"ʋ","ʋ̩","",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//唇齿
        jbAppend(this->p_resultToOutput,uliy->checkedId(),"β̞","β̞̩","",this->ugmf,this->ugdd,this->ulii,this->bi,this->yriy,this->igybjp->isChecked());//双唇
        if(this->p_resultToOutput->isEmpty()==0&&this->yriy->checkedId()==YRIYYRNUMBER)//在近音的情况下,如果圆唇程度是"圆",添加圆唇符号
        {
            this->p_resultToOutput->append("ʷ");
        }
        if(this->p_resultToOutput->isEmpty())//此时如果待输出区仍然没有字符,说明是元音
        {
            //添加元音符号
            switch(this->yriy->checkedId())
            {
                case YRIYYRNUMBER://圆唇
                {
                    this->p_resultToOutput->append(mapOfRoundedVowels->value(this->uegf->checkedId()));
                    break;
                }
                case YRIYVSNUMBER://中
                {
                    this->p_resultToOutput->append(mapOfUnroundedVowels->value(this->uegf->checkedId()));
                    this->p_resultToOutput->append("̹");
                    break;
                }
                case YRIYVJNUMBER://展唇
                {
                    this->p_resultToOutput->append(mapOfUnroundedVowels->value(this->uegf->checkedId()));
                    break;
                }
                default:
                {
                    break;
                }
            }
            if(ui->bikd->isChecked())//如果鼻腔打开,那么添加鼻化符号
            {
                this->p_resultToOutput->append("̃");
            }
            if(ui->ugddjk->isChecked())//如果声带不振动,那么添加清化符号
            {
                this->p_resultToOutput->append("̊");
            }
            if(ui->yriyvs->isChecked())//如果圆唇程度为"中",那么添加一个"更圆唇"符号
            {
                this->p_resultToOutput->append("̹");
            }
            if(ui->igybjp->isChecked()==0)//如果不成音节,那么添加一个不成音节符号
            {
                this->p_resultToOutput->append("̯");
            }
            if(ui->uliisi->isChecked())//如果有咝音,那么添加齿化符号
            {
                this->p_resultToOutput->append("̪");
            }
            if(ui->ugmfhu->isChecked())//如果声门呼气,那么添加呼气符号
            {
                this->p_resultToOutput->append("↑");
            }
            else if(ui->ugmfhu->isChecked())//如果声门吸气,那么添加吸气符号
            {
                this->p_resultToOutput->append("↓");
            }
        }
        //最后,无论是近音还是元音,添加协同调音标记
        xptsAppendForTs(this->p_resultToOutput,uegf->checkedId(),"ˤ","ˤᶩ");//舌根
        xptsAppendForTs(this->p_resultToOutput,xnue->checkedId(),"ˀ","\U0001079C");//小舌
        xptsAppendForTs(this->p_resultToOutput,rree->checkedId(),"ˠ","ᶫ");//软腭
        xptsAppendForTs(this->p_resultToOutput,eeyh->checkedId(),"ᶡ","\U000107A1");//腭央
        xptsAppendForTs(this->p_resultToOutput,ykee->checkedId(),"ʲ","\U000107A0");//硬腭
        switch(uejm_getPlace(uejm->checkedId()))//舌尖
        {
            case JRUENUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ʵ","ᶩ");//卷舌
                break;
            }
            case YBHZNUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶾ","ᶾˡ");//龈后
                break;
            }
            case XXFUNUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶨ","");//下阜
                break;
            }
            case YBEENUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶽ","ᶽˡ");//龈颚
                break;
            }
            case IIYBNUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶻ","ᶻˡ");//齿龈
                break;
            }
            case IIUENUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶞ","ᶞˡ");//齿舌
                break;
            }
            case IYUENUMBER:
            {
                xptsAppendForTs(this->p_resultToOutput,uejm->checkedId()%MAJORPLACEBUTTONMAX,"ᶞ̼","ˡ̼");//齿舌
                break;
            }
            default:
            {
                break;
            }
        }
        xptsAppendForTs(this->p_resultToOutput,iyii->checkedId(),"ᶹ","");//唇齿
        xptsAppendForTs(this->p_resultToOutput,uliy->checkedId(),"ᵝ","");//双唇
    }
    //最后,如果是吸气状态,而用以表示吸气状态的字符过少或过多,则调整数量,使向下箭头只有一个,并转移到最后
    if(this->ugmf->checkedId()==UGMFXINUMBER)
    {
        //首先删除所有的吸气箭头
        p_resultToOutput->replace("↓","");
        //如果有内爆音或喌音符号,就什么也不做,否则在最后添加一个吸气箭头
        if(
            (p_resultToOutput->indexOf("ʛ")+1)
            ||(p_resultToOutput->indexOf("ɠ")+1)
            ||(p_resultToOutput->indexOf("ʄ")+1)
            ||(p_resultToOutput->indexOf("ᶑ")+1)
            ||(p_resultToOutput->indexOf("ɗ")+1)
            ||(p_resultToOutput->indexOf("ɓ")+1)
            ||(p_resultToOutput->indexOf("ǀ")+1)
            ||(p_resultToOutput->indexOf("ǁ")+1)
            ||(p_resultToOutput->indexOf("ǂ")+1)
            ||(p_resultToOutput->indexOf("ǃ")+1)
            ||(p_resultToOutput->indexOf("ʘ")+1)
          )
        {
            ;
        }
        else
        {
            p_resultToOutput->append("↓");
        }
    }
    //如果是呼气状态,而用以表示呼气状态的字符过少或过多,则调整数量,使向上箭头只有一个,并转移到最后
    else if(this->ugmf->checkedId()==UGMFHUNUMBER)
    {
        if(p_resultToOutput->contains("↑"))
            {
                p_resultToOutput->replace("↑","");
                p_resultToOutput->append("↑");
            }
    }
    ui->resultDisplayer->setText("\n");
    ui->resultDisplayer->append(*p_resultToOutput);
}
