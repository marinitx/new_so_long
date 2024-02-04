<img src="https://github.com/marinitx/so_long/assets/123256807/32a0289d-6dc8-4444-bb36-7f5e0f13fe05">

<h1>Instrucciones</h1>

<p>Para comenzar, clona este repositorio y desde la terminal llama primero al ejecutable y luego al mapa que desees de entre los creados seguido de un espacio. Si quieres puedes <a href="#create">crear tu propio mapa.</a></p>
<img width="185" alt="solong" src="https://github.com/marinitx/so_long/assets/123256807/5a76f8e6-75fa-4d7c-833b-3acbaa3d3938">

<p>El objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.</p>
<ul>
  <li>Utiliza las teclas W, A, S, D para mover a la ranita (arriba, izquierda, abajo y derecha, respectivamente).</li>
  <li>Los nenúfares actúan de barrera: no puedes atravesarlos.</li>
  <li>Tras cada movimiento, el número real de movimientos se muestra en la terminal.</li>
  <li>Para poder llegar a la salida (la roca), necesitarás primero comerte todas las moscas.</li>
  <li>Los mapas que no tengan un camino válido para llegar a la salida o que no te permitan comerte todas las moscas, serán considerados nulos.</li>
</ul>
<img width="547" alt="terminal" src="https://github.com/marinitx/so_long/assets/123256807/6b0b196b-dddf-4a41-a4af-67870824d356">

<h2 id="create">Crea tu propio mapa</h2>

<p>Para crear tu propio mapa y que sea válido, deberás crear un nuevo archivo ".ber". Este contendrá el dibujo de tu mapa.</p>
<ol>
  <li>Representa el camino de agua con "0".</li>
  <li>Representa las paredes de nenúfar con "1".</li>
  <li>Representa UNA rana con "P".</li>
  <li>Representa UNA piedra (salida) con "E".</li>
  <li>Representa tantas moscas como quieras con "C".</li>
  <li>Cualquier otro carácter será inválido.</li>
</ol>

<h2>MLX</h2>
<p>Es posible que el juego no funcione sin instalar MLX antes. Puedes instalarlo <a href="https://ml-explore.github.io/mlx/build/html/install.html">aquí</a></p>
