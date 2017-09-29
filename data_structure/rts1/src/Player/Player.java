// Παπαϊωαννου Ευαγγελος 7229 pevangek@auth.gr 
// Λιολιόπουλος Αλεξανδρος-Πολυχρόνης 7204 alexaras99@msn.com alexanld@auth.gr 

package Player;

import java.util.ArrayList;
import java.util.Vector;

import Platform.Utilities;
import Units.Base;
import Units.Marine;
import Units.Unit;

public class Player implements AbstractPlayer
{

  private int id;
  private int startX;
  private int startY;

  ArrayList<Unit> units = new ArrayList<Unit>();

  // (Integer pid)
  // Ειναι ο constructor της κλασης player, δεχεται το id του παικτη και καλει συναρτηση για να τον βαλει στην καταλληλη βαση.
  public Player (Integer pid)
  {
	  id=pid;
	  setStartXY(id);
  }
  // Η συναρτηση που καλειτε απο τον constructor και δινει αρχικες τιμες στη βαση του παικτη.
  public void setStartXY(int id){
	  if(id==1){
		  startX=10;
		  startY=150;
	  }
	  else{
		  startX=790;
		  startY=150;
	  }
	  
  }
  
  // Επιστρεφει το id του παικτη της κλασης
  public int getId(){
	  return id;
  }
  // Επιστρεφει το Χ της βασης του παικτη της κλασης
  public int getStartX(){
	  return startX;
  }
  
  // Επιστρεφει το Υ της βασης του παικτη της κλασης
  public int getStartY(){
	  return startY;
  }
  
  // Επιστρεφει το ονομα του παικτη της κλασης
  public String getName(){
	  return "Player1";
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

  // TODO
  
  // Δημιουργω ενα αντικειμενο τυπου base χρησιμοποιωντας τις μεταβλητες του τρεχοντος αντικειμενου(this) και αυξανω τον δεικτη unitid οπως και την ουρα
  Base createInitialBase (int unitId)
  {
	  int id;
	  int startX;
	  int startY;
	  id=this.id;
	  startX=this.startX;
	  startY=this.startY;
	  Base initialBase= new Base (unitId, id, startX, startY);
	    Utilities.unitID++;
	    units.add(initialBase);
	    return initialBase;
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

  // TODO
  
  // Ακριβως αναλογα με την createinitialbase 
  Marine createInitialMarine (int unitId)
  {
	  int id;
	  int startX;
	  int startY;
	  id=this.id;
	  startX=this.startX;
	  startY=this.startY;
	  Marine initialMarine= new Marine (unitId, id, startX, startY);
	    Utilities.unitID++;
	    units.add(initialMarine);
	    return initialMarine;
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

  public void setUnits (ArrayList<Unit> unitlist)
  {
    units = unitlist;
  }

  public void chooseCorridor (ArrayList<Unit> units)
  {

    for (Unit uni: units) {

      if (uni.getCorridor() == -1 && uni.getType() == "marine"
          && uni.getOwner() == id) {

        // For these units choose the corridor in which they will move
        uni.setCorridor(chooseRandomCorridor());
        // uni.corridor=0;
        uni.setStatus(Unit.Moving);
        uni.setPrevStatus(Unit.Standing);

      }
    }

  }

  // redesign resolveAttacking for unit to attack the weakest available unit
  // System.out.println(uni.getOwner()+" "+enemyuni.getOwner()+" "+uni.getType()+" "+id+" "+Utilities.getDistance(uni,
  // enemyuni)+ " "+uni.attack_range);

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

    int i = 0, j = 0;
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

  // TODO
  
  // Με την συναρτηση random επιλεγουμε τυχαια εναν απο τους τρεις διαδρομους και κανουμε type casting σε integer επειδη επιστρεφει double.
  public int chooseRandomCorridor ()
  {
	return (int)Math.floor((Math.random()*3));
  }

}
