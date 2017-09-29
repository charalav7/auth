package Player;

import java.util.ArrayList;
import java.util.Vector;

import Platform.Utilities;
import Units.Base;
import Units.Marine;
import Units.Unit;

public class HeuristicPlayer implements AbstractPlayer
{

  private int id;
  private int startX;
  private int startY;

  ArrayList<Unit> units = new ArrayList<Unit>();

  public HeuristicPlayer (Integer pid)
  {
    id = pid;
    if (pid == Utilities.PLAYERA_ID) {
      startX = Utilities.PLAYERA_STARTX;
      startY = Utilities.PLAYERA_STARTY;
    }
    else {
      startX = Utilities.PLAYERB_STARTX;
      startY = Utilities.PLAYERB_STARTY;

    }
  }

  public int getId ()
  {
    return id;
  }

  public int getStartX ()
  {
    return startX;
  }

  public int getStartY ()
  {
    return startY;
  }

  public void setId (int id)
  {
    this.id = id;
  }

  public void setStartX (int startX)
  {
    this.startX = startX;
  }

  public void setStartY (int startY)
  {
    this.startX = startY;
  }

  public String setName ()
  {
    return "Heuristic";
  }

  public void initialize (int startMarines)
  {
    units.clear();

    units.add(createInitialBase(Utilities.unitID));
    Utilities.unitID++;
    for (int i = 0; i < startMarines; i++) {

      units.add(createInitialMarine(Utilities.unitID));
      Utilities.unitID++;
    }

  }

  Base createInitialBase (int unitId)
  {
    return new Base(unitId, id, startX, startY);
  }

  void createBase (int id, int ownerID, int startingX, int startingY)
  {
    Base base = new Base(id, ownerID, startingX, startingY);
    Utilities.unitID++;
    units.add(base);

  }

  public void createBase ()
  {
    createBase(Utilities.unitID, id, startX, startY);

  }

  Marine createInitialMarine (int unitId)
  {
    return new Marine(unitId, id, startX, startY);

  }

  void createMarine (int id, int ownerID, int startingX, int startingY)
  {
    Marine marine = new Marine(id, ownerID, startingX, startingY);
    Utilities.unitID++;
    units.add(marine);

  }

  public void createMarine ()
  {
    createMarine(Utilities.unitID, id, startX, startY);
  }

  public ArrayList<Unit> getUnits ()
  {
    return units;

  }

  public ArrayList<Unit> getOwnUnits ()
  {
    ArrayList<Unit> ownUnits = new ArrayList<Unit>();
    for (Unit uni: units) {
      if (uni.getOwner() == id)
        ownUnits.add(uni);
    }
    return ownUnits;

  }

  public ArrayList<Marine> getStationaryMarines ()
  {
    ArrayList<Marine> ownUnits = new ArrayList<Marine>();
    for (Unit uni: units) {
      if (uni.getOwner() == id && uni.isMarine() && uni.getCorridor() == -1)
        ownUnits.add((Marine) uni);
    }
    return ownUnits;

  }

  public void setUnits (ArrayList<Unit> unitlist)
  {
    units = unitlist;
  }

  // TODO
  public void chooseCorridor (ArrayList<Marine> marines)
  {
	  double[] s=new double[3]; // δεσμευση πινακα 3 θεσεων
	  int m=marines.size(); // παιρνω το μεγεθος του arraylist
	  double max=0;
	  int cor=0;
	  for(int j=0;j<m;j++){ 
		  Marine mar=marines.get(j);
		  if(mar.getStatus()==0){ //φιλτραρισμα των στατικων στρατιωτων
			  for(int i=0;i<3;i++){
				  s[i]=evaluate(i); //κληση της evaluate 3 φορες και τοποθετηση του αποτελεσματος σε πινακα
			  }
			  for(int i=0;i<3;i++){
				  if(s[i]>max){
					  max=s[i];
					  cor=i; // επιλογη του μεγιστου στοιχειου και κατ επεκτασιν του διαδρομου με το max evaluation
					  
				  }
			  }
		  }
		  mar.movingToCorridor(cor); // στελνουμε το στρατιωτακι στον διαδρομο που επιλεχθηκε
	  }
 }

  // TODO
  private double evaluate (int corridor)
  {
	 int s0=0;
	 int s1=0;
	 int s2=0;
	 int p0=0;
	 int p1=0;
	 int p2=0; // αρχικοποιηση των αθροιστων
	 ArrayList<Marine> myMarine=new ArrayList<Marine>();
	 ArrayList<Marine> opMarine=new ArrayList<Marine>();
	 //Κριτηριο 1: Ο αριθμος των στρατιωτων που εχει καθε παραταξη στον καθε διαδρομο.
	 int n=units.size(); // παιρνω το μεγεθος του arraylist units
	 for (int i=0;i<n;i++){
		 Unit u=units.get(i); // επιστρεφει το αντικειμενο που βρισκεται στην θεση i και το αντιστοιχιζει στο u
		 if((u.getOwner()==this.id)&&(u.isMarine()==true)){ // φιλτραρισμα για το αν ειναι δικος μας στρατιωτης
			 myMarine.add((Marine)u); // προσθηκη του στοιχειου στον arraylist myMarine
		  if(u.getCorridor()==0){
			 s0=s0+1;
		  }
		  else if (u.getCorridor()==1){
			 s1=s1+1;
			 }
		  else if (u.getCorridor()==2){
			 s2=s2+1; // υπολογιζουμε τον αριθμο των στρατιωτων μας σε καθε διαδρομο
		  }
		 }
	 }
	 for (int i=0;i<n;i++){ // αντιστοιχα για τον αντιπαλο
		 Unit u=units.get(i);
		 if((u.getOwner()!=this.id)&&(u.isMarine()==true)){
			 opMarine.add((Marine)u);
		  if(u.getCorridor()==0){
			 p0=p0+1;
		  }
		  else if (u.getCorridor()==1){
			 p1=p1+1;
			 }
		  else if (u.getCorridor()==2){
			 p2=p2+1;
		  } 
		 }
	 }
	 
	 if (corridor==0) s0=s0+1; // προσθετουμε μια μοναδα αναλογα με το ορισμα που δεχθηκαμε
	 else if (corridor==1) s1=s1+1;
	 else s2=s2+1;
	 
	 int o0=s0-p0;
	// System.out.println(o0);
	 int o1=s1-p1;
	 int o2=s2-p2; // υπολογιζουμε τις διαφορες στον αριθμο των στρατιωτων σε καθε διαδρομο
	 
	 float ev0=o0/(s0+p0+1)*100;
	 float ev1=o1/(s1+p1+1)*100;
	 float ev2=o2/(s2+p2+1)*100; // προσπαθουμε να βγαλουμε εναν λόγο
	 
	 double evf=(ev0+ev1+ev2)/3; // και εναν τελικο αριθμο για το κριτηριο αυτο
	 
	 float ev01=0;
	 // Κριτηριο 2: Αν υπαρχουν στρατιωτες που επιτιθενται στη βαση μας η στην βαση του αντιπαλου.
	 int k=myMarine.size();
	 for (int i=0;i<k;i++){
		 Marine m=myMarine.get(i);
		 if((m.isAttackingBase()==true)){
			 int cor=m.getCorridor();
			 if (corridor==cor) ev01+=70;
			 
		 } // ελεγχουμε αν επιτιθεμεθα στην βαση του αντιπαλου κι αν ναι αυξανουμε τον δεικτη του evaluate
	 }
	 
	 float ev011=0;
	 int l=opMarine.size();
	 for (int i=0;i<l;i++){
		 Marine op=opMarine.get(i);
		 if((op.isAttackingBase()==true)){
			 int cor=op.getCorridor();
			 if (corridor==cor) ev011+=150;
			 
		 }
	 } // αντιστοιχα για το αν δεχομαστε επιθεση, με τη διαφορα οτι δινουμε μεγαλυτερη βαρυτητα

	 double eval= (evf+ev01+ev011)/3;
	 return eval; // επιστρεφουμε εναν τελικο "μεσο ορο" της καταστασης του ταμπλο
	 
	 
	 
	  
  }

  public void resolveAttacking (ArrayList<Unit> unitlist)
  {
    for (Unit uni: unitlist) {
      Vector<Vector<Integer>> targets = new Vector<Vector<Integer>>();

      for (Unit enemyuni: unitlist) {
        // && uni.corridor == enemyuni.corridor
        if (uni.getOwner() == id && uni.getStatus() != Unit.Attacking
            && uni.getType() == "marine" && enemyuni.getOwner() != id
            && Utilities.getDistance(uni, enemyuni) <= uni.getAttackRange()
            && uni.getCorridor() == enemyuni.getCorridor()
            || uni.getOwner() == id && uni.getStatus() != Unit.Attacking
            && uni.getType() == "marine" && enemyuni.getOwner() != id
            && Utilities.getDistance(uni, enemyuni) <= uni.getAttackRange()
            && enemyuni.getType() == "base") {

          Vector<Integer> target = new Vector<Integer>();
          target.add(enemyuni.getId());
          target.add(enemyuni.getCurrentHP());
          target.add(enemyuni.getX());
          target.add(enemyuni.getY());

          targets.add(target);

        }
      }
      if (!targets.isEmpty()) {
        Vector<Integer> weakest = Utilities.findTheWeakest(targets);

        uni.setStatus(Unit.Attacking);
        uni.setTargetX(weakest.get(2));
        uni.setTargetY(weakest.get(3));
        uni.setPrevStatus(Unit.Moving);

        for (Unit enemyuni: unitlist) {
          if (enemyuni.getId() == weakest.get(0)) {
            enemyuni.setDamageSuffered(enemyuni.getDamageSuffered()
                                       + (uni.getAttackSpeed() * uni
                                               .getDamage()));
          }
        }
      }

    }
  }

  public Vector<Vector<Integer>> sendDamages (ArrayList<Unit> unitlist)
  {
    Vector<Vector<Integer>> damages = new Vector<Vector<Integer>>();

    for (Unit uni: unitlist) {
      if (uni.getOwner() != id && uni.getDamageSuffered() > 0) {
        Vector<Integer> dam = new Vector<Integer>();
        dam.add(uni.getId());
        dam.add(uni.getDamageSuffered());
        damages.add(dam);

      }
    }
    if (damages.size() == 0) {
      Vector<Integer> dam = new Vector<Integer>();
      dam.add(-1);
      dam.add(0);
      damages.add(dam);
    }

    return damages;
  }

  public void receiveDamages (Vector<Vector<Integer>> damages)
  {
    while (!damages.isEmpty()) {
      Vector<Integer> dam = new Vector<Integer>();
      dam = damages.remove(0);
      for (Unit uni: units) {
        if (uni.getId() == dam.get(0))
          uni.setDamageSuffered(dam.get(1));
      }
    }
  }

  public void resolveDamages (ArrayList<Unit> unitlist)
  {

    int i = unitlist.size() - 1;
    while (i >= 0) {
      if (unitlist.get(i).getOwner() == id) {
        if (unitlist.get(i).getCurrentHP() > unitlist.get(i)
                .getDamageSuffered()) {
          unitlist.get(i).setCurrentHP(unitlist.get(i).getCurrentHP()
                                               - unitlist.get(i)
                                                       .getDamageSuffered());
          unitlist.get(i).setDamageSuffered(0);
        }
        else {
          unitlist.remove(i);

        }
      }
      i--;

    }

  }

  public void moveUnits (ArrayList<Unit> units)
  {

    for (Unit uni: units) {
      if (uni.getOwner() == id && uni.getStatus() == Unit.Moving) {

        if (uni.getDestX() == -1)
          Utilities.setFirstDestination(uni);
        if (uni.getDestX() == uni.getX() && uni.getDestY() == uni.getY())
          Utilities.setDestination(uni);
        if (uni.getX() > uni.getDestX())
          uni.setX(uni.getX() - uni.getSpeed());
        if (uni.getX() < uni.getDestX())
          uni.setX(uni.getX() + uni.getSpeed());
        if (uni.getY() > uni.getDestY())
          uni.setY(uni.getY() - uni.getSpeed());
        if (uni.getY() < uni.getDestY())
          uni.setY(uni.getY() + uni.getSpeed());
        uni.setPrevStatus(Unit.Moving);

      }
      if (uni.getOwner() == id && uni.getStatus() == Unit.Attacking) {
        uni.setStatus(Unit.Moving);
        uni.setPrevStatus(Unit.Attacking);
      }
    }

  }

}
