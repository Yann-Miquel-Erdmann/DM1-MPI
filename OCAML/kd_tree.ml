type vector = float array
type kd_tree = Vide | Node of int * vector * kd_tree * kd_tree

(* GÉNÉRATION JEU TEST *)
let genere_jeu_donnes (n : int) : vector array =
  Array.init n (fun i -> Array.init 2 (fun _ -> Random.float 1.))

(* OUTILS GRAPHIQUES *)

let yellow = Graphics.rgb 210 160 4
let cx = 500
let cy = 500
let to_x pt = pt *. float_of_int cx |> int_of_float
let to_y pt = pt *. float_of_int cy |> int_of_float

let rec draw_kd_tree_aux (t : kd_tree) swx swy nex ney =
  match t with
  | Vide -> ()
  | Node (dim, v_sep, g, d) ->
      let dx, dy = (to_x v_sep.(0), to_y v_sep.(1)) in
      if dim = 0 then (
        Graphics.set_color Graphics.black;
        Graphics.moveto dx swy;
        Graphics.lineto dx ney;
        Graphics.set_color yellow;
        Graphics.fill_circle dx dy 5;
        draw_kd_tree_aux g swx swy dx ney;
        draw_kd_tree_aux d dx swy nex ney
      )
      else (
        Graphics.set_color Graphics.black;
        Graphics.moveto swx dy;
        Graphics.lineto nex dy;
        Graphics.set_color yellow;
        Graphics.fill_circle dx dy 5;
        draw_kd_tree_aux g swx swy nex dy;
        draw_kd_tree_aux d swx dy nex ney
      )

let draw_kd_tree (t : kd_tree) =
  (* Hyp : fenêtre graphique de taille cx * cy ouverte
     dessine l'arbre t
  *)
  draw_kd_tree_aux t 0 0 cx cy

(* renvoie une fonction de comparaison qui compare deux vecteurs sur leur i-ème composante*)
let f_cmp (i : int) : vector -> vector -> bool =
 fun (v1 : vector) (v2 : vector) -> v1.(i) <= v2.(i)


let partition (t : 'a array) (d : int) (f : int) (p : int) (cmp : 'a -> 'a -> bool) : int =
  (* échange les éléments aux indices i et j dans t *)
  let swap (i: int) (j: int): unit =
    let temp = t.(i) in
    t.(i) <- t.(j);
    t.(j) <- temp;
  in

  swap p d;

  let a = ref (d + 1) in
  let b = ref f in

  while !a <= !b do
    if cmp t.(!a) t.(d) then 
      a := !a + 1
    else(      
      swap !a !b;
      b := !b - 1
    )
  done;

  swap d (!a-1);
  !a - 1

let rec selection_rapide (t : vector array) (d : int) (f : int) (r : int)
    (cmp : vector -> vector -> bool) : vector =
  if d <= f then
    let p = d (* + Random.int (f - d) *) in
    let q = partition t d f p cmp in
    if r = q then t.(q)
    else (   
      if r < q then 
        selection_rapide t d (q - 1) r cmp
      else 
        selection_rapide t (q + 1) f r cmp
    )
  else failwith "liste vide ou erreur d'indices d et f"

let cree_arbre_kd (t : vector array) : kd_tree =
  let dim = Array.length t.(0) in
  let rec cree_arbre_dk_indice (d : int) (f : int) (i : int) : kd_tree =
    if f < d then 
      Vide
    else(
      let r = (d + f) / 2 in
      let valeur = selection_rapide t d f r (f_cmp i) in
      let a_g = cree_arbre_dk_indice d (r - 1) ((i + 1) mod dim) in
      let a_d = cree_arbre_dk_indice (r + 1) f ((i + 1) mod dim) in
      Node (i, valeur , a_g, a_d)
    )
  in

  cree_arbre_dk_indice 0 (Array.length t - 1) 0

let main_exemple () =
  let nb_points = 10000 in
  let t = genere_jeu_donnes nb_points  in
  let kd_tree = cree_arbre_kd t  in 
  Graphics.open_graph " 500x500";
  draw_kd_tree kd_tree;
  Graphics.loop_at_exit [] (fun _ -> ())

let a = main_exemple ()
