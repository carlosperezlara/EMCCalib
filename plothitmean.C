void style(TGraphErrors *gr, TGraph *gr2) {
  gr->GetXaxis()->SetNdivisions(504);
  gr->GetXaxis()->SetLabelSize(0.07);
  gr->SetLineColor( kGray );
  gr->SetMarkerColor( kRed-3 );
  gr->SetMarkerStyle( 20 );
  gr2->SetLineColor( kBlue-3 );
  gr2->SetMarkerColor( kBlue-3 );
  gr2->SetMarkerStyle( 22 );
}

int plothitmean() {
  ifstream fin("dat/hitmean.dat");
  int n=0;
  float run[120];
  float erun[120];
  float sec0[120];
  float sec1[120];
  float sec2[120];
  float sec3[120];
  float sec4[120];
  float sec5[120];
  float sec6[120];
  float sec7[120];
  float msec0[120];
  float msec1[120];
  float msec2[120];
  float msec3[120];
  float msec4[120];
  float msec5[120];
  float msec6[120];
  float msec7[120];
  float ssec0[120];
  float ssec1[120];
  float ssec2[120];
  float ssec3[120];
  float ssec4[120];
  float ssec5[120];
  float ssec6[120];
  float ssec7[120];
  const int nbruns = 0;
  int bruns[1];
  /*
  const int nbruns = 8;
  int bruns[nbruns] = {455224,455449,//no stats
		       455352, // many deads in sec 0, 1
		       455063, 455064, // many dead in sec 3, 4
		       455220, // many dead in sec 4
		       455082, 455209 // many deads in sec 7
		       
  };
  */
  for(;;) {
    fin >> run[n];
    if(!fin.good()) break;
    fin >> sec0[n] >> sec1[n] >> sec2[n] >> sec3[n];
    fin >> sec4[n] >> sec5[n] >> sec6[n] >> sec7[n];
    fin >> msec0[n] >> ssec0[n] >> msec1[n] >> ssec1[n];
    fin >> msec2[n] >> ssec2[n] >> msec3[n] >> ssec3[n];
    fin >> msec4[n] >> ssec4[n] >> msec5[n] >> ssec5[n];
    fin >> msec6[n] >> ssec6[n] >> msec7[n] >> ssec7[n];
    erun[n] = 0;
    bool skip = false;
    for(int k=0; k!=nbruns; ++k)
      if(run[n]==bruns[k]) skip=true;
    if(skip) continue;
    /*
    if(sec0[n]<0.01) cout << " Sector 0 tag run " << run[n] << endl;
    if(sec1[n]<0.01) cout << " Sector 1 tag run " << run[n] << endl;
    if(sec2[n]<0.01) cout << " Sector 2 tag run " << run[n] << endl;
    if(sec3[n]<0.01) cout << " Sector 3 tag run " << run[n] << endl;
    if(sec4[n]<0.01) cout << " Sector 4 tag run " << run[n] << endl;
    if(sec5[n]<0.01) cout << " Sector 5 tag run " << run[n] << endl;
    if(sec6[n]<0.01) cout << " Sector 6 tag run " << run[n] << endl;
    if(sec7[n]<0.01) cout << " Sector 7 tag run " << run[n] << endl;
    */
    ++n;
  }
  cout << n << " runs" << endl;

  TGraph *gSec0 = new TGraph( n, run, sec0 );
  TGraph *gSec1 = new TGraph( n, run, sec1 );
  TGraph *gSec2 = new TGraph( n, run, sec2 );
  TGraph *gSec3 = new TGraph( n, run, sec3 );
  TGraph *gSec4 = new TGraph( n, run, sec4 );
  TGraph *gSec5 = new TGraph( n, run, sec5 );
  TGraph *gSec6 = new TGraph( n, run, sec6 );
  TGraph *gSec7 = new TGraph( n, run, sec7 );

  TGraphErrors *geSec0 = new TGraphErrors( n, run, msec0, erun, ssec0 );
  TGraphErrors *geSec1 = new TGraphErrors( n, run, msec1, erun, ssec1 );
  TGraphErrors *geSec2 = new TGraphErrors( n, run, msec2, erun, ssec2 );
  TGraphErrors *geSec3 = new TGraphErrors( n, run, msec3, erun, ssec3 );
  TGraphErrors *geSec4 = new TGraphErrors( n, run, msec4, erun, ssec4 );
  TGraphErrors *geSec5 = new TGraphErrors( n, run, msec5, erun, ssec5 );
  TGraphErrors *geSec6 = new TGraphErrors( n, run, msec6, erun, ssec6 );
  TGraphErrors *geSec7 = new TGraphErrors( n, run, msec7, erun, ssec7 );

  TCanvas *main = new TCanvas("main","",1300,600);
  main->Divide(4,2);
  main->cd(1); geSec0->Draw("A*L"); gSec0->Draw("PSAME");
  main->cd(2); geSec1->Draw("A*L"); gSec1->Draw("PSAME");
  main->cd(3); geSec2->Draw("A*L"); gSec2->Draw("PSAME");
  main->cd(4); geSec3->Draw("A*L"); gSec3->Draw("PSAME");
  main->cd(5); geSec4->Draw("A*L"); gSec4->Draw("PSAME");
  main->cd(6); geSec5->Draw("A*L"); gSec5->Draw("PSAME");
  main->cd(7); geSec6->Draw("A*L"); gSec6->Draw("PSAME");
  main->cd(8); geSec7->Draw("A*L"); gSec7->Draw("PSAME");

  double amin = 0.16;
  double amax = 0.26;
  double bmin = 0.04;
  double bmax = 0.10;
  gSec0->GetYaxis()->SetRangeUser(amin,amax);
  gSec1->GetYaxis()->SetRangeUser(amin,amax);
  gSec2->GetYaxis()->SetRangeUser(amin,amax);
  gSec3->GetYaxis()->SetRangeUser(amin,amax);
  gSec4->GetYaxis()->SetRangeUser(amin,amax);
  gSec5->GetYaxis()->SetRangeUser(amin,amax);
  gSec6->GetYaxis()->SetRangeUser(bmin,bmax);
  gSec7->GetYaxis()->SetRangeUser(bmin,bmax);

  style(geSec0,gSec0);
  style(geSec1,gSec1);
  style(geSec2,gSec2);
  style(geSec3,gSec3);
  style(geSec4,gSec4);
  style(geSec5,gSec5);
  style(geSec6,gSec6);
  style(geSec7,gSec7);

  return 0;
}
