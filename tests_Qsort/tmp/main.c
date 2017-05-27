#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient
{
  char nom[20];
  int num;
  int nss;
  int priorite;
}Patient;

typedef struct ListP *Hospital;
typedef struct ListP
{
  Patient P;
  Hospital suivant;
}ListP;

void CreerListeP(Hospital *H)
{
  H=NULL;
}

void InitPatient(Patient *Pat,char n[],int ordre,int ss,int pr)
{
  Pat->nss=ss;
  Pat->num=ordre;
  Pat->priorite=pr;
  strcpy(Pat->nom,n);
}

void InsererP(Hospital *H,Patient Pat)
{
  ListP* Courant=(*H);
  ListP* Prec=NULL;
  ListP* Nouveau;
  Nouveau=(ListP*)malloc(sizeof(ListP));
  Nouveau->P=Pat;
  while(Courant!=NULL && Courant->P.priorite>Pat.priorite)
    {
      Prec=Courant;
      Courant=Courant->suivant;
    }
  Nouveau->suivant=Courant;
  if(Prec!=NULL)
    {
      Prec->suivant=Nouveau;
    }
  else
    {
      (*H)=Nouveau;
    }
}

ListP* VerifierP(Hospital H,Patient Pat)
{
  ListP* Tmp=H;
  while(Tmp!=NULL)
    {
      if(Tmp->P.nss==Pat.nss)
	{
	  return(Tmp);
	}
      Tmp=Tmp->suivant;
    }
  return(NULL);

}

void EnleverP(Hospital *H,Patient Pat)
{
  ListP* Courant=(*H),*Prec=NULL;
  ListP* Tmp=VerifierP(*H,Pat);
  if(Tmp!=NULL)
    {
      while(Courant!=NULL && Courant!=Tmp)
	{
	  Prec=Courant;
	  Courant=Courant->suivant;
	}
      Prec->suivant=Courant->suivant;
      free(Courant);
    }
}

int NbPriorite(Hospital H,int PR)
{
  int Cpt=0;
  ListP* Tmp=H;
  while(Tmp!=NULL)
    {
      if(Tmp->P.priorite==PR)
	{
	  Cpt++;
	}
      Tmp=Tmp->suivant;
    }
  return(Cpt);
}

void AfficherListe(Hospital H)
{
  ListP* Tmp=H;
  while(Tmp!=NULL)
    {
      printf("Nom:%s\tNss:%d\tPriorite:%d\n",Tmp->P.nom,Tmp->P.nss,Tmp->P.priorite);
      Tmp=Tmp->suivant;
    }
}

int NbPatient(Hospital H)
{
  ListP* Tmp=H;
  int C=0;
  while(Tmp!=NULL)
    {
      C++;
      Tmp=Tmp->suivant;
    }
  return(C);
}

void Trier(Hospital *H)
{
  ListP* Tmp1,*Tmp2;
  ListP* Permut;
  Patient min;

  for(Tmp1=(*H);Tmp1!=NULL;Tmp1=Tmp1->suivant)
    {
      Permut=Tmp1;
      min=Tmp1->P;
      for(Tmp2=Tmp1->suivant;Tmp2!=NULL;Tmp2=Tmp2->suivant);
      {
	if(Tmp2->P.priorite<min.priorite)
	  {
	    Permut=Tmp2;
	    min=Permut->P;
	  }
      }
      Permut->P=Tmp1->P;
      Tmp1->P=min;
    }


}

int main()
{
  Patient P1,P2,P3,P4;
  Hospital H;
  InitPatient(&P1,"X",22,1234,2);
  InitPatient(&P2,"Y",11,1245,1);
  InitPatient(&P3,"Z",10,4321,3);
  InitPatient(&P4,"T",9,3214,1);
  CreerListeP(&H);
  InsererP(&H,P3);
  InsererP(&H,P2);
  InsererP(&H,P1);
  InsererP(&H,P4);
  AfficherListe(H);
  EnleverP(&H,P2);
  printf("Liste Apres Supression\n");
  AfficherListe(H);
  Trier(&H);
  printf("Liste Apres Modification\n");
  AfficherListe(H);
  return 0;
}
