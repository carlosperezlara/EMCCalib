#include "defs2.h"

int main(int argc, char *argv[]){
  //===================
  //const int kNTWRS = 24768;
  //unsigned int kBBCnc = 0x00000008;
  //unsigned int kBBCn  = 0x00000010;
  int secs[9] = { 0, 2592, 5184, 7776, 10368,
		  12960, 15552, 20160, 24768 };
  unsigned int trig = kBBCnc | kBBCn;

  int isc,iz,iy;
  TH2F *hHitTwr = new TH2F("SectorTwr","EmcIndexer;TowerID;Sector", 24768,-0.5,24767.5,8,-0.5,7.5);
  for(unsigned int i=0; i!=24768 ;++i) {
    int twid = i;
    EmcIndexer::decodeTowerId(twid,isc,iz,iy);
    hHitTwr->Fill(twid,isc);
  }
  hHitTwr->SaveAs("geo.SectorTwr.root");
  return 0;
}
