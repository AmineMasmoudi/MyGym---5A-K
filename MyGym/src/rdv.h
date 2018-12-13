typedef struct
{
int heure;
int jour;
int mois;
int annee;
}Date;
typedef struct
{
char staff[20];
Date dt_res;
int hr_resr;
}ReservationRdv;
int tableau_date_reserver(ReservationRdv tab[50]);
int verifier_rdv(ReservationRdv Rv);
int tableau_date_disponible(char Date dt_res, char staff, int hr_resr);
void reserver_date(ReservationRdv r);
