const hex = [0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F']; // #f15402 color code
		const btn = document.querySelector('#btn');
		const color = document.querySelector('.color');
		
		btn.addEventListener('click', function(){
			let hexColor = '#';  			// not using 'const' because we are going to add values in let
			for(let i = 0; i < 6; i++) {
				hexColor += hex[getRandomNumber()];
			}
			
			color.textContent = hexColor;
			document.body.style.backgroundColor = hexColor;
			
			function getRandomNumber() {
				return Math.floor(Math.random() * hex.length)
			}
			console.log(getRandomNumber());
		})