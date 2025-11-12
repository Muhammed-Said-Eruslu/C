"groups:"; printf "%s" "  - "; id -Gnz | awk 'BEGIN{FS="\0"; OFS="\n  - "}{NF--; print}'
