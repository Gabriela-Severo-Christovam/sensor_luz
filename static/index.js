document.addEventListener('DOMContentLoaded', async function() {
    const resultado = document.getElementById('result');

    const response = await fetch('https://projeto-sensor-luz.onrender.com/get/estado_lampada');
    const estado_luz = await response.json();

    const estadoLuz = estado_luz.ESTADO_LAMPADA; 
    resultado.innerHTML = `<span>${estadoLuz}</span>`;
});
