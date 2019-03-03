for f in *.txt; do
	echo $f
	exten="${f##*.}"
	filename="${f%.*}"
	extenT="${filename##*.}"
	echo $extenT
	if [ "$extenT" = "out" ]; then
		mv -- "$f" "${f%.txt}.out"
	fi
	if [ "$extenT" = "tout" ]; then
		mv -- "$f" "${f%.txt}.tout"
	fi
	
done

for f in *.out; do
	newname=$(echo $f | cut -d '.' -f1)
	mv -- "$f" "${newname}.out"

	if [ "$extenT" = "tout" ]; then
		mv -- "$f" "${newname}.tout"
	fi
done
for f in *.tout; do
	newname=$(echo $f | cut -d '.' -f1)
	mv -- "$f" "${newname}.tout"
done